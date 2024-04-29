import { useState, useEffect } from "react";
import React from 'react'

/* components, state, and props along with two hooks && onclick event */ 

const App = () => {
  // this is the state of the app
  // never alter the state manually only with its setter function
  const [counter, setCounter] = useState(0);

  // useEffect loads up upon rendering
  useEffect(() => {
    alert("You've changed the counter to " + counter);
  }, [counter]) // everytime the counter changes this will re render

  return (
    <div className="app">
      <button
        onClick={()=> setCounter((prevCount) => prevCount - 1)}
      >
        -
      </button>
      <h1>{counter}</h1>
      <button
        onClick={()=> setCounter((prevCount) => prevCount + 1)}
      >
        +
      </button>
    </div>
  )
}

export default App