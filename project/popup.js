document.addEventListener('DOMContentLoaded', function() {
    // Add event listener to start button
    document.getElementById('startButton').addEventListener('click', function() {
      // Send message to background script to start the stopwatch
      chrome.runtime.sendMessage({ action: 'startStopwatch' });
    });
  
    // Add event listener to stop button
    document.getElementById('stopButton').addEventListener('click', function() {
      // Send message to background script to stop the stopwatch
      chrome.runtime.sendMessage({ action: 'stopStopwatch' });
    });
  });
  