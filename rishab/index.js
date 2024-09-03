// Set the target date (YYYY-MM-DD format)
const BDate = new Date('2024-01-09T13:09:00');

// Update the timer every second
setInterval(updateTimer, 1000);

function updateTimer() {
  const currentDate = new Date();
  const timeDifference =  currentDate - BDate;

  // Calculate time components
  const days = Math.floor(timeDifference / (1000 * 60 * 60 * 24));
  const hours = Math.floor((timeDifference % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  const minutes = Math.floor((timeDifference % (1000 * 60 * 60)) / (1000 * 60));
  const seconds = Math.floor((timeDifference % (1000 * 60)) / 1000);

  // Display the timer
  const timerElement = document.getElementById('timer');
  timerElement.innerHTML = `${days}Days ${hours}Hours ${minutes}Minutes ${seconds}Seconds`;
}
