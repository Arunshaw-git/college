import './App.css';
import Header from "./MyComponents/Header"
import Footer from "./MyComponents/Footer"
import ToDos from "./MyComponents/ToDos"
import ToDo from "./MyComponents/ToDo"

function App() {

  let todos =[
    {
      sno:1,
      title: "Go to the market",
      desc:"You need to go to the market"
    },
    {
      sno:2,
      title: "Go to the mall",
      desc:"You need to buy a shirt "
    },
    {
      sno:3,
      title:"Go to the space",
      desc:"You need to go the space to cheange the sun"
    },
   
  ]
  return (
    <>  
      <Header title= 'Mytodoslist' searchBar ={true} />
      <ToDos todos = {todos}/>
      <Footer/>
    </>
   
  );
}

 

export default App;
