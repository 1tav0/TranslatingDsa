function pickComputerMove(){
  const num = Math.random();
  let computerMove = '';
  if(num>=0 && num<=1/3){
    computerMove = 'rock';
  }else if(num>=1/3 && num<=2/3){
    computerMove = 'paper';
  }else if(num>=2/3 && num<=1){
    computerMove = 'scissor';
  }
  return computerMove;
}

function playGame(playerMove){
  const computerMove = pickComputerMove();
  let result = '';
  if(playerMove=="rock"){
    if(computerMove=="rock"){
      result = "tie";
    }else if(computerMove=="scissor"){
      result = "win";
    }else{
      result = "loose";
    }
  }else if(playerMove=="paper"){
    if(computerMove=="rock"){
      result = "win";
    }else if(computerMove=="scissor"){
      result = "loose";
    }else{
      result = "tie";
    }
  }else if(playerMove=="scissor"){
    if(computerMove=="rock"){
      result = "loose";
    }else if(computerMove=="scissor"){
      result = "tie";
    }else{
      result = "win";
    }
  }
}
