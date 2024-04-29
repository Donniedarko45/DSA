let player1Name = prompt("Enter Player 1's Name:"); 
let player2Name = prompt("Enter Player 2's Name:");
let currentPlayer = "X"; 
let currentPlayerName = player1Name;
let arr = Array(9).fill(null);

function checkWinner() {
  if (
    (arr[0] !== null && arr[0] === arr[1] && arr[1] === arr[2]) ||
    (arr[3] !== null && arr[3] === arr[4] && arr[4] === arr[5]) ||
    (arr[6] !== null && arr[6] === arr[7] && arr[7] === arr[8]) ||
    (arr[0] !== null && arr[0] === arr[3] && arr[3] === arr[6]) ||
    (arr[1] !== null && arr[1] === arr[4] && arr[4] === arr[7]) ||
    (arr[2] !== null && arr[2] === arr[5] && arr[5] === arr[8]) ||
    (arr[0] !== null && arr[0] === arr[4] && arr[4] === arr[8]) ||
    (arr[2] !== null && arr[2] === arr[4] && arr[4] === arr[6])
  ) {
    let winnerName = currentPlayer === "X" ? player1Name : player2Name;
    document.write(`Congratulations now give me party, ${winnerName}!`);
    return;
  }

  if (!arr.some((value) => value === null)) {
    document.write(`Draw!!`);
    return;
  }
}

function handleClick(element) {
  const id = Number(element.id);
  if (arr[id] !== null) return;
  arr[id] = currentPlayer;
  element.innerText = currentPlayer;
  checkWinner();

  currentPlayer = currentPlayer === "X" ? "O" : "X";
  currentPlayerName = currentPlayerName === player1Name ? player2Name : player1Name;
}
