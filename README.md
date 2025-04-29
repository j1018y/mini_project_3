NTHU I2P3   MiniChess AI

# MiniChess AI

## Project Overview
This project focuses on building an AI agent that can autonomously play **MiniChess**, a simplified version of traditional chess.  
The AI reads the current board state, evaluates possible moves using a **state value function**, and determines the optimal move using a **tree search algorithm** such as **Minimax** or **Alpha-Beta Pruning**.

---

## Game Rules Summary

- **Players**: Two (White and Black); White moves first.
- **Winning Condition**: Capture the opponent’s King.
- **Pawn Promotion**: Pawns promote only to Queens upon reaching the last row.
- **Illegal Moves**: Result in immediate loss.
- **Special Rules**:
  - No castling.
  - No en passant.
- **Draw Condition**:  
  If the game exceeds 50 moves (25 turns), the player with the higher total piece value wins.  
  Piece values:
  - Queen = 20
  - Bishop = 8
  - Knight = 7
  - Rook = 6
  - Pawn = 2

---

## Technical Overview

### 1. Board Representation
- Board size: **5 × 6** grid.
- Pieces are encoded as:
  - 0: Empty
  - 1: Pawn
  - 2: Rook
  - 3: Knight
  - 4: Bishop
  - 5: Queen
  - 6: King

### 2. Input and Output

- **Input File**: `state`
  - Player turn (0 = White, 1 = Black)
  - White's board layout (5 lines)
  - Black's board layout (5 lines)

- **Output File**: `action`
  - Move format: `from_y from_x to_y to_x`

### 3. Key Components

- **State Value Function**:  
  Evaluates the desirability of a given board state.

- **Tree Search Algorithms**:
  - **Minimax**: Simulates all possible move sequences to choose the optimal path.
  - **Alpha-Beta Pruning**: Optimizes Minimax by cutting off branches that cannot influence the final decision.

- **Utilities Provided**:
  - State management (generating legal actions, board transitions).
  - Example random move agent.

---

## Development Guidelines

- Implement a **custom state value function** to evaluate board states effectively.
- Implement a **Minimax search algorithm** for move planning.
- Optimize the search with **Alpha-Beta Pruning** to explore deeper moves within time constraints.
- Comply with standard C++ development practices using the provided project structure.

---

## Running the Project

### Compilation
```bash
make all
