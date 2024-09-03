

document.querySelectorAll('.container').forEach(container =>{
    container.addEventListener('click', ()=>{
        container.classList.toggle('expanded')
        const textElement = container.querySelector('.text');
        if (textElement) {
            textElement.innerHTML = ""; // Clear the text content
        }
    });

});
