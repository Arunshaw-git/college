console.log("background.js loaded");

chrome.tabs.onUpdated.addListener((tabId, changeInfo, tab) => {
  console.log(`Tab updated: ${tabId}`, changeInfo, tab);

  if (changeInfo.status === 'complete' && tab.url.includes('youtube.com/watch')) {
    console.log('YouTube video detected, injecting content script...');
    chrome.scripting.executeScript({
      target: { tabId: tabId },
      files: ['content.js']
    });
  }
});

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.action === 'showNotification') {
    console.log('Showing notification...');
    chrome.notifications.create('educationalVideo', {
      type: 'basic',
      iconUrl: 'icon.png',
      title: 'Educational Video Detected',
      message: 'An educational video is playing. Start your stopwatch!'
    }, () => {
      // Send a response back to the content script
      sendResponse({ success: true, message: 'Notification shown' });
    });
  }

  // Return true to indicate that the response will be sent asynchronously
  return true;
});
