# Memory-Game
A simple text-based memory-matching game implemented in C++. The game features a 4x4 grid of cards, which players can flip over to find matching pairs.

## Features

- **Randomized Card Placement**: Cards are shuffled to random positions at the start of the game, ensuring each playthrough is unique.
- **User Interaction**: Players are prompted to enter coordinates to flip two cards and find matches. The game includes input validation to ensure valid moves within the grid.
- **Game State Management**: Tracks the player's progress, including the number of turns taken. The game saves the result to a file upon completion or if the player decides to quit early.
- **File I/O**: The game results, including the player's name and the number of turns taken, are saved to a text file (`gameHistory.txt`).

## How to Play

1. Run the program, and you will be welcomed and prompted to enter your full name.
2. The game displays a 4x4 grid of cards, initially faced down (`*`).
3. Enter the coordinates of two cards to flip them over.
4. If the two cards match, they will remain face up.
5. If the cards do not match, they will be temporarily flipped to show their values, then flipped back over.
6. Continue flipping cards until all pairs are found.
7. The game saves your progress, including the number of turns you took, to a text file.
8. You can quit the game at any time by entering 'q'.

## Getting Started

### Prerequisites
- A C++ compiler
- A command-line interface (CLI)

## Installation

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/jessica-nguyen-dev/Memory-Game.git

2.  Navigate to the project directory:
    ```bash
    cd memory-game

3. Compile the C++ program:
   ```bash

4. Run the compiled program:
   ```bash
   ./memory_game
