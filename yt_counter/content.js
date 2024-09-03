(function() {
  function isEducationalVideo() {
    const title = document.title.toLowerCase();
    const educationalKeywords = ['course', 'tutorial', 'lesson', 'how to', 'guide'];
    console.log('Video title:', title);
    const isEducational = educationalKeywords.some(keyword => title.includes(keyword));
    console.log('Is educational:', isEducational);
    return isEducational;
  }

  function checkVideoStatus() {
    console.log('Educational is playing...');

    const video = document.querySelector('video');
    if (video && !video.paused && isEducationalVideo()) {
      chrome.runtime.sendMessage({ action: 'showNotification' }, response => {
        if (chrome.runtime.lastError) {
          console.error('Error sending message:', chrome.runtime.lastError.message);
        } 
        
         else {
          console.log('Message sent successfully. Response:', response);
        }
      });
      console.log('Educational video is playing...');
    } else {
      console.log('No educational video playing or video is paused.');
    }
  }

  setInterval(checkVideoStatus, 5000);
})();
