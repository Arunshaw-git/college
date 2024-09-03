// Function to send a message to the background script when a video is played
function sendMessageToBackground() {
    // Prompt user to confirm if the video is educational
    if (confirm('Is this video educational? Click OK to start the stopwatch.')) {
      // Send message to background script to start the stopwatch
      chrome.runtime.sendMessage({ action: 'startStopwatch' });
    }
  }
  
  // Listen for page load
  window.addEventListener('load', function() {
    // Send message to background script when page is loaded
    sendMessageToBackground();
  });
  
  // Listen for video playback events and send message to background script
  document.addEventListener('yt-navigate-finish', sendMessageToBackground);
  document.addEventListener('spfcb', sendMessageToBackground);
  