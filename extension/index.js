let myleads =[];
const inputEl = document.getElementById("inputEl")
const ulEl= document.getElementById("ulEl")

const leadsfromlocal = JSON.parse(localStorage.getItem("myleads"))

if(leadsfromlocal){
    myleads = leadsfromlocal;
    render()
}

let btn = document.getElementById("btn")
btn.addEventListener("click",() => {
    myleads.push(inputEl.value)
    localStorage.setItem("myleads", JSON.stringify(myleads))
    
    render()
    inputEl.value =""

} );

document.getElementById("del").addEventListener("dblclick",()=>{
    localStorage.clear()
    myleads=[]
    render()

});

document.getElementById("tab").addEventListener("click",()=>{
    chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
        let currentTab = tabs[0];
        myleads.push(currentTab.url)
        localStorage.setItem("myleads",JSON.stringify(myleads))
        render()
    })
})
/*
function save(){
    console.log("clicked");

}
    used when adding onclick in the tag
*/
function render(){

let listItems = ""

for (let i = 0; i<myleads.length;i++){
    //first method(best one) (contentText cant make a html element)
    //ulEl.innerHTML+= "<li>" + myleads[i] + "</li>"
    

    /*second method
    const li = document.createElement("li")
    li.textContent =myleads[i]
    ulEl.append(li)*/
    //third method(in this we make a string and add all the items in it and then render it )
    //listItems+="<li><a href='" + myleads[i] +"' target=' _blank'>" +myleads[i]+ "</a></li>"
    listItems+=`
                <li>
                    <a href=${myleads[i]} target=' _blank'>
                    ${myleads[i]} 
                    </a>
                </li>
    `
}
//${xyz}-> string template
//rendering it ( DOM manipulation has a cost, so we only manipulate it once)
ulEl.innerHTML =listItems
}

