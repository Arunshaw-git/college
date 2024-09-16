import React from 'react'
import ToDo from './ToDo'

const ToDos = (props) => {
  return (
    <div className = "container">
        <h3 className="text-center">Todos List</h3>
        {props.todos.map((todo)=>{
            return <ToDo todo ={todo} onDelete ={onDelete}/>
        })}
    </div>
  )
}

export default ToDos
