# Rubik's Cube Solver

This project implements a Rubik's Cube solver using **Korf's Algorithm**, an optimal solution method for solving the cube in the minimum number of moves. The solver is designed to explore and demonstrate advanced search techniques and heuristics in solving the Rubik's Cube.

---

## Key Highlights

- **C++ for Performance**: The solver is implemented in C++ to ensure high performance.
- **God's Number**: In 2010, it was proven that any Rubik's Cube configuration can be solved in 20 moves or fewer, known as "God's Number."
- **Entropy Insight**: The maximum entropy of the Rubik's Cube is achieved in 20 moves.

---

## Features

- Implements **Korf's Algorithm** to solve the Rubik's Cube in the fewest possible moves.
- Provides an interactive way to input cube states.
- Displays a step-by-step solution.
- Extendable and modular design for integrating additional solving algorithms.

---

## Table of Contents

- [Introduction](#introduction)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm Overview](#algorithm-overview)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

---

## Introduction

The Rubik's Cube Solver project uses **Korf's Algorithm**, a state-of-the-art technique for solving the cube optimally. Korf's Algorithm combines:

- **Iterative Deepening A* (IDA*)**: A search technique to find the shortest solution.
- **Pattern Databases**: Precomputed tables storing minimal moves to solve specific cube configurations.

This project is ideal for enthusiasts and students interested in learning about algorithms, heuristics, and problem-solving in computer science.

---

## How It Works

1. **Input**: The user provides the cube's current scrambled state.
2. **Initialization**: The solver initializes heuristic values using precomputed pattern databases.
3. **Search**: The algorithm explores possible move sequences to find the optimal solution.
4. **Output**: The optimal solution sequence and intermediate cube states are displayed.

---

## Installation

### Prerequisites

- A C++ compiler (e.g., GCC, MinGW).
- CMake for building the project.

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/rubiks-cube-solver.git
   cd rubiks-cube-solver
   ```

2. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the solver:
   ```bash
   ./RubiksCubeSolver
   ```

---

## Usage

1. Launch the program and follow the prompts to input the cube state.
2. The solver will compute and display the solution step-by-step.
3. For visual representation, a GUI can be enabled (if implemented).

---

## Algorithm Overview

### Korf's Algorithm

Korf's Algorithm solves the Rubik's Cube using the following steps:

- **Problem Representation**: The cube is represented as a state tree where each node is a configuration.
- **Iterative Deepening A***: Combines depth-first search's space efficiency with breadth-first search's optimality.
- **Heuristics**: Pattern databases store precomputed optimal solutions for subproblems (e.g., corners, edges).

### Why Korf's Algorithm?

- Guarantees the optimal solution.
- Efficient use of memory with iterative deepening.
- Demonstrates advanced algorithmic concepts.

---

## Project Structure

```
Rubiks-Cube-Solver/
├── main.cpp            # Entry point of the program
├── README.md           # Documentation
├── CMakeLists.txt      # Build configuration
├── Models/             # Cube models and representations
├── Solvers/            # Algorithm implementations
├── PatternDatabases/   # Precomputed pattern databases
├── Inputs/             # Input files for testing
├── Databases/          # Additional data resources
├── build/              # Build directory
└── Tests/              # Unit tests
```

---

## Contributing

Contributions are welcome! If you want to contribute:

1. Fork the repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes and push to the branch:
   ```bash
   git push origin feature-name
   ```
4. Open a pull request.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---