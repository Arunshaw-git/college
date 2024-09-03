// Global variables to hold timer interval and elapsed time
let timerInterval;
let elapsedTime = 0;

// Listen for messages from content script or popup script
chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.action === 'startStopwatch') {
    // Start the stopwatch
    startTimer();
  } else if (message.action === 'stopStopwatch') {
    // Stop the stopwatch
    stopTimer();
  }
});

// Function to start the stopwatch
function startTimer() {
  // Reset elapsed time to 0
  elapsedTime = 0;

  // Start timer interval
  timerInterval = setInterval(updateTimer, 1000);
}

// Function to stop the stopwatch
function stopTimer() {
  // Clear timer interval
  clearInterval(timerInterval);
}

// Function to update the stopwatch display
function updateTimer() {
  // Increment elapsed time by 1 second
  elapsedTime += 1;

  // Calculate hours, minutes, and seconds
  const hours = Math.floor(elapsedTime / 3600);
  const minutes = Math.floor((elapsedTime % 3600) / 60);
  const seconds = elapsedTime % 60;

  // Format time components with leading zeros if needed
  const formattedTime = `${String(hours).padStart(2, '0')}:${String(minutes).padStart(2, '0')}:${String(seconds).padStart(2, '0')}`;

  // Send message to update the timer display in the popup
  chrome.runtime.sendMessage({ action: 'updateTimer', time: formattedTime });
}
