const myBox = document.getElementById("box");

function changecolor(event){
    event.target.style.backgroundImage = "url('https://i1.sndcdn.com/artworks-ASgQ6A59p6tfUyeT-7DIEpg-t240x240.jpg')";
    event.target.textContent ="";
  
}

myBox.addEventListener("click",changecolor);