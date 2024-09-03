let start = document.getElementById("start")
let stop = document.getElementById("stop")
let display= document.getElementById("stopwatch")
let time = 0
let intervalId;
let running = false;

start.addEventListener('click', startStopwatch);  
stopStopwatch.addEventListener('click', stopStopwatch);
function formatTime(seconds) {
    const hrs = Math.floor(seconds / 3600);
    const mins = Math.floor((seconds % 3600) / 60);
    const secs = seconds % 60;

    return `${hrs.toString().padStart(2, '0')}h:${mins.toString().padStart(2, '0')}m:${secs.toString().padStart(2, '0')}s`;
}

function startStopwatch() {
    if (!running) {
        running = true;
        intervalId = setInterval(() => {
            time++;
            updateDisplay();
        }, 1000);
    }
}
function updateDisplay() {
    display.textContent = formatTime(time);
}
function stopStopwatch() {
    if (running) {
        clearInterval(intervalId);
        running = false;
    }
}
let reset = document.getElementById("reset").addEventListener("click",()=>{
    clearInterval(intervalId);
    running = false;
    time= 0
    updateDisplay()
})