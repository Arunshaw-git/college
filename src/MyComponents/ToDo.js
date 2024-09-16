import React from 'react'

const ToDo = ({todo,onDelete }) => {
  return (
    <div>
      <h4>{todo.title}</h4>
      <p>{todo.desc}</p>
      <button className='btn  btn-sm btn-danger' onClick ={onDelete}
      >DELETE</button>
    </div>
   
  )
}

export default ToDo
