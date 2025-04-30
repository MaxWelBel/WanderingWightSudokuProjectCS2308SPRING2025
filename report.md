# WanderingWightSudokuProject - Spring2025

## Overview

In the **Overview** section, briefly summarize the project’s **objective**, core **functionalities**, and key **outcomes**. Highlight the **main goal** (e.g., developing a Sudoku solver), major **challenges** faced, and the strategies or algorithms used to overcome them. Mention any notable **technical achievements**, such as optimizations or different modes (**DEBUG**/**non-DEBUG**).

The objective of this program is to create an efficient sudoku solver. The core functionalities of this program include: using a guess and check backtracking method and using a Minimum-Remaining Value heuristic with the prior in a separate function. A key outcome of this project is that even though we dub the function "efficient" it's actually slower than the basic method. I did not have have any challenges writing the code as the TODO explanation was very thorough but the docstrings were a little difficult for me as I wasn't exactly sure how much I had to put down be given the examples. In the end I opted for a more brief but enough for someone knowledgeable to understand.

In the next paragraph, reflect on the **skills** and **knowledge** gained, like improvements in **problem-solving**, **code optimization**, or **collaboration**. If applicable, mention how the team worked together and how the project contributed to your overall learning experience.

## Part 1: Complete the Code
**GitHub Repository Link:** [WanderingWightProject](https://github.com/MaxWelBel/WanderingWightSudokuProjectCS2308SPRING2025)

**Collaborators Added:**
- Instructor: `keshavsbhandari`
- TA: `tousifulhaque`
- Team Members: `MaxWelBel` - Maxwell Belcher `A0532123` (ihq15@txstate.edu) 

---

## Part 2: Program Flow Visualization

**Flowchart for Sudoku Solver Execution (Non-DEBUG Mode):**

```text
main()
│
├── initDataFolder()
│   │
│   ├── createFolder("data/") 
│   │   └──[Creates a folder on the system if the folder does not exist]
│   ├── createFolder("data/puzzles/") 
│   │   └──[Creates a folder on the system if the folder does not exist]
│   └── createFolder("data/solutions/") 
│       └──[Creates a folder on the system if the folder does not exist]
│   
├── createAndSaveNPuzzles(10, 45, "data/puzzles/", "PUZZLE")
│   │
│   ├── generateBoard(45);
│   │   │
│   │   ├── getEmptyBoard()
│   │   │   └── [Dynamically allocates an empty 9x9 sudoku board]
│   │   │
│   │   ├── fillBoardWithIndependentBox(BOARD)
│   │   │   │
│   │   │   ├── getShuffledVector()
│   │   │   │   └── [Returns a vector with the numbers 1-9 shuffled using the mersenne-twister engine seeded with random_device]
│   │   │   │
│   │   │   └── [The above function is called 3 times for 3 separate boxes in a for loop]
│   │   │   └── [Fills 3 3x3 diagonally top-left to bottom-right with random numbers 1-9]
│   │   │
│   │   ├── solveBoard(BOARD);
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoard(BOARD, r, c+1) until board is solved]
│   │   │
│   │   ├── deleteRandomItems(BOARD, 45)
│   │   │   └── [Uses the mersenne-twister engine seeded with random_device to randomly select row and column position to delete]
│   │   │   └── [Ensures it does not delete what is already deleted]
│   │   │   └── [Repeats in a for loop a total of 45 times]
│   │   │
│   │   └── [Returns a 9x9 sudoku board with 45 empty boxes]
│   │
│   ├── getFileName(index, "data/puzzles/", "PUZZLE")
│   │   └── [Returns a string to the relative path to the file to be created]
│   │   └── [Example for index 1: "data/puzzles/0001PUZZLE.txt"]
│   │
│   ├── writeSudokuToFile(BOARD, filename) 
│   │   │
│   │   ├── boardToString(BOARD, content)
│   │   │   └── [Converts the sudoku board to a string and appends it to content which is an empty string] 
│   │   │
│   │   └── [Writes content to the file described by filename]
│   │   └── [Returns true if the file was written successfully and false if not]
│   │
│   ├── deallocateBoard(BOARD)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   └── [index is incremented in a for loop 9 times for each board]
│   └── [Creates 10 solvable sudoku puzzles and saves them to data/puzzles]
│   
├── solveAndSaveNPuzzles(10, "data/puzzles/", "data/solutions/", "SOLUTIONS")
│   │
│   ├── getAllSudokuInFolder("data/puzzles")
│   │   │
│   │   └── [Returns a string vector containing the absolute paths to the sudoku puzzles]
│   │
│   ├── readSudokuFromFile(path_to_sudokus[i])
│   │   │
│   │   ├── replaceCharacter(sudoku, '-', '0')
│   │   │   └── [Replaces all instances of '-' with '0' in the sudoku stringstream reference]
│   │   │
│   │   ├── extractNumbers(sudoku, numbers)
│   │   │   └── [Uses regex to translate the characters to numbers in the sudoku stringstream and adds them to the numbers vector]
│   │   │
│   │   ├── fillBoard(numbers, BOARD)
│   │   │   └── [Fills the sudoku BOARD with all the numbers in the numbers vector from 0 to 81]
│   │   │
│   │   └── [Returns a sudoku board read from a file on the system]
│   │
│   ├── solve(sudoku)
│   │   │
│   │   ├── solveBoard(board, 0, 0)
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoard(BOARD, r, c+1) until board is solved]
│   │   │
│   │   └── [Returns the function call to solveBoard() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(sudoku)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── getFileName(i, "data/solutions", "SOLUTION")
│   │   └── [Returns a string to the relative path to the file to be created]
│   │   └── [Example for index 1: "data/puzzles/0001SOLUTION.txt"]
│   │
│   ├── writeSudokuToFile(sudoku, filename)
│   │   │
│   │   ├── boardToString(BOARD, content)
│   │   │   └── [Converts the sudoku board to a string and appends it to content which is an empty string] 
│   │   │
│   │   └── [Writes content to the file described by filename]
│   │   └── [Returns true if the file was written successfully and false if not]
│   │
│   ├── deallocateBoard(sudoku)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   └── [index is incremented in a for loop 9 times for each board]
│   └── [Solves 10 puzzles provided in data/puzzles and saves them to data/solutions]
│
├── compareSudokuSolvers(10, 64)
│   │
│   ├── generateBoard(64)
│   │   │
│   │   ├── getEmptyBoard()
│   │   │   └── [Dynamically allocates an empty 9x9 sudoku board]
│   │   │
│   │   ├── fillBoardWithIndependentBox(BOARD)
│   │   │   │
│   │   │   ├── getShuffledVector()
│   │   │   │   └── [Returns a vector with the numbers 1-9 shuffled using the mersenne-twister engine seeded with random_device]
│   │   │   │
│   │   │   └── [The above function is called 3 times for 3 separate boxes in a for loop]
│   │   │   └── [Fills 3 3x3 diagonally top-left to bottom-right with random numbers 1-9]
│   │   │
│   │   ├── solveBoard(BOARD);
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls until board is solved]
│   │   │
│   │   ├── deleteRandomItems(BOARD, 64)
│   │   │   └── [Uses the mersenne-twister engine seeded with random_device to randomly select row and column position to delete]
│   │   │   └── [Ensures it does not delete what is already deleted]
│   │   │   └── [Repeats in a for loop a total of 64 times]
│   │   │
│   │   └── [Returns a 9x9 sudoku board with 64 empty boxes]
│   │
│   ├── deepCopyBoard(board1)
│   │   └── [Creates a deep copy by making a new board double pointer and copying values 1-by-1]
│   │
│   ├── solve(board1, true)
│   │   │
│   │   ├── solveBoardEfficient(board)
│   │   │   │
│   │   │   ├── findNextCell()
│   │   │   │   │
│   │   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │   │
│   │   │   │   └── [Returns a tuple to the position of the cell with the least amount of valid options or the first cell with 1 option]
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoardEfficient() until board is solved]
│   │   │   
│   │   └── [Returns the function call to solveBoardEfficient() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(board1)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── deallocateBoard(board1)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   ├── solve(board2)
│   │   │
│   │   ├── solveBoard(board, 0, 0)
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoard(BOARD, r, c+1) until board is solved]
│   │   │
│   │   └── [Returns the function call to solveBoard() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(board2)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── deallocateBoard(board2)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   ├── displayProgressBar(i, 10)
│   │   └── [Displays a progress bar equivalent to i/10 of the full size]
│   │
│   └── [This process is repeated a total of 10 times in a for loop]
│   └── [Outputs the number of experiments, average time taken on solveBoard(), number of valid solutions of solveBoard(), ]
│   └── [average time taken on solveBoardEfficient(), number of valid solutions of solveBoardEfficient()]
│
├── compareSudokuSolvers(100, 45)
│   │
│   ├── generateBoard(45)
│   │   │
│   │   ├── getEmptyBoard()
│   │   │   └── [Dynamically allocates an empty 9x9 sudoku board]
│   │   │
│   │   ├── fillBoardWithIndependentBox(BOARD)
│   │   │   │
│   │   │   ├── getShuffledVector()
│   │   │   │   └── [Returns a vector with the numbers 1-9 shuffled using the mersenne-twister engine seeded with random_device]
│   │   │   │
│   │   │   └── [The above function is called 3 times for 3 separate boxes in a for loop]
│   │   │   └── [Fills 3 3x3 diagonally top-left to bottom-right with random numbers 1-9]
│   │   │
│   │   ├── solveBoard(BOARD);
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls until board is solved]
│   │   │
│   │   ├── deleteRandomItems(BOARD, 45)
│   │   │   └── [Uses the mersenne-twister engine seeded with random_device to randomly select row and column position to delete]
│   │   │   └── [Ensures it does not delete what is already deleted]
│   │   │   └── [Repeats in a for loop a total of 45 times]
│   │   │
│   │   └── [Returns a 9x9 sudoku board with 45 empty boxes]
│   │
│   ├── deepCopyBoard(board1)
│   │   └── [Creates a deep copy by making a new board double pointer and copying values 1-by-1]
│   │
│   ├── solve(board1, true)
│   │   │
│   │   ├── solveBoardEfficient(board)
│   │   │   │
│   │   │   ├── findNextCell()
│   │   │   │   │
│   │   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │   │
│   │   │   │   └── [Returns a tuple to the position of the cell with the least amount of valid options or the first cell with 1 option]
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoardEfficient() until board is solved]
│   │   │   
│   │   └── [Returns the function call to solveBoardEfficient() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(board1)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── deallocateBoard(board1)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   ├── solve(board2)
│   │   │
│   │   ├── solveBoard(board, 0, 0)
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoard(BOARD, r, c+1) until board is solved]
│   │   │
│   │   └── [Returns the function call to solveBoard() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(board2)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── deallocateBoard(board2)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   ├── displayProgressBar(i, 100)
│   │   └── [Displays a progress bar equivalent to i/100 of the full size]
│   │
│   └── [This process is repeated a total of 100 times in a for loop]
│   └── [Outputs the number of experiments, average time taken on solveBoard(), number of valid solutions of solveBoard(), ]
│   └── [average time taken on solveBoardEfficient(), number of valid solutions of solveBoardEfficient()]
│
├── compareSudokuSolvers(1000, 32)
│   │
│   ├── generateBoard(32)
│   │   │
│   │   ├── getEmptyBoard()
│   │   │   └── [Dynamically allocates an empty 9x9 sudoku board]
│   │   │
│   │   ├── fillBoardWithIndependentBox(BOARD)
│   │   │   │
│   │   │   ├── getShuffledVector()
│   │   │   │   └── [Returns a vector with the numbers 1-9 shuffled using the mersenne-twister engine seeded with random_device]
│   │   │   │
│   │   │   └── [The above function is called 3 times for 3 separate boxes in a for loop]
│   │   │   └── [Fills 3 3x3 diagonally top-left to bottom-right with random numbers 1-9]
│   │   │
│   │   ├── solveBoard(BOARD);
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls until board is solved]
│   │   │
│   │   ├── deleteRandomItems(BOARD, 32)
│   │   │   └── [Uses the mersenne-twister engine seeded with random_device to randomly select row and column position to delete]
│   │   │   └── [Ensures it does not delete what is already deleted]
│   │   │   └── [Repeats in a for loop a total of 32 times]
│   │   │
│   │   └── [Returns a 9x9 sudoku board with 32 empty boxes]
│   │
│   ├── deepCopyBoard(board1)
│   │   └── [Creates a deep copy by making a new board double pointer and copying values 1-by-1]
│   │
│   ├── solve(board1, true)
│   │   │
│   │   ├── solveBoardEfficient(board)
│   │   │   │
│   │   │   ├── findNextCell()
│   │   │   │   │
│   │   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │   │
│   │   │   │   └── [Returns a tuple to the position of the cell with the least amount of valid options or the first cell with 1 option]
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoardEfficient() until board is solved]
│   │   │   
│   │   └── [Returns the function call to solveBoardEfficient() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(board1)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── deallocateBoard(board1)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   ├── solve(board2)
│   │   │
│   │   ├── solveBoard(board, 0, 0)
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoard(BOARD, r, c+1) until board is solved]
│   │   │
│   │   └── [Returns the function call to solveBoard() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(board2)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── deallocateBoard(board2)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   ├── displayProgressBar(i, 1000)
│   │   └── [Displays a progress bar equivalent to i/1000 of the full size]
│   │
│   └── [This process is repeated a total of 1000 times in a for loop]
│   └── [Outputs the number of experiments, average time taken on solveBoard(), number of valid solutions of solveBoard(), ]
│   └── [average time taken on solveBoardEfficient(), number of valid solutions of solveBoardEfficient()]
│
├── compareSudokuSolvers(10000, 16)
│   │
│   ├── generateBoard(16)
│   │   │
│   │   ├── getEmptyBoard()
│   │   │   └── [Dynamically allocates an empty 9x9 sudoku board]
│   │   │
│   │   ├── fillBoardWithIndependentBox(BOARD)
│   │   │   │
│   │   │   ├── getShuffledVector()
│   │   │   │   └── [Returns a vector with the numbers 1-9 shuffled using the mersenne-twister engine seeded with random_device]
│   │   │   │
│   │   │   └── [The above function is called 3 times for 3 separate boxes in a for loop]
│   │   │   └── [Fills 3 3x3 diagonally top-left to bottom-right with random numbers 1-9]
│   │   │
│   │   ├── solveBoard(BOARD);
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls until board is solved]
│   │   │
│   │   ├── deleteRandomItems(BOARD, 16)
│   │   │   └── [Uses the mersenne-twister engine seeded with random_device to randomly select row and column position to delete]
│   │   │   └── [Ensures it does not delete what is already deleted]
│   │   │   └── [Repeats in a for loop a total of 16 times]
│   │   │
│   │   └── [Returns a 9x9 sudoku board with 16 empty boxes]
│   │
│   ├── deepCopyBoard(board1)
│   │   └── [Creates a deep copy by making a new board double pointer and copying values 1-by-1]
│   │
│   ├── solve(board1, true)
│   │   │
│   │   ├── solveBoardEfficient(board)
│   │   │   │
│   │   │   ├── findNextCell()
│   │   │   │   │
│   │   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │   │
│   │   │   │   └── [Returns a tuple to the position of the cell with the least amount of valid options or the first cell with 1 option]
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoardEfficient() until board is solved]
│   │   │   
│   │   └── [Returns the function call to solveBoardEfficient() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(board1)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── deallocateBoard(board1)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   ├── solve(board2)
│   │   │
│   │   ├── solveBoard(board, 0, 0)
│   │   │   │
│   │   │   ├── isValid(BOARD, r, c, k)
│   │   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │   │
│   │   │   └── [Recursively calls solveBoard(BOARD, r, c+1) until board is solved]
│   │   │
│   │   └── [Returns the function call to solveBoard() acting as a link]
│   │
│   ├── checkIfSolutionIsValid(board2)
│   │   │
│   │   ├── isValid(BOARD, r, c, k)
│   │   │   └── [Checks the 3x3 box, column c, and row r for the value k in the board BOARD to determine if the value k can be placed there]
│   │   │   └── [This function call is placed within a for loop from 1-9]
│   │   │
│   │   └── [Checks to make sure every number is valid 1-by-1; returns true if so and false if not]
│   │
│   ├── deallocateBoard(board2)
│   │   └── [Dynamically deallocates the sudoku board first by each row pointer then by the double pointer to the board itself]
│   │
│   ├── displayProgressBar(i, 10000)
│   │   └── [Displays a progress bar equivalent to i/10000 of the full size]
│   │
│   └── [This process is repeated a total of 10000 times in a for loop]
│   └── [Outputs the number of experiments, average time taken on solveBoard(), number of valid solutions of solveBoard(), ]
│   └── [average time taken on solveBoardEfficient(), number of valid solutions of solveBoardEfficient()]
│
└── [Returns 0 to signify successful program execution]


```

This flow illustrates the general steps the program takes in non-DEBUG mode, from initializing the puzzle to saving the solved result.

---

## Part 3: Reflective Questions

1. **Group Photo:**

   *(Insert group photo here)*


2. **What contributions did your friends make? List them.**

    - **[MaxWelBel]:** Everything.

3. **Why do you think `efficientSolver` took more time than the regular solver? What strategies would you implement to make `efficientSolver` actually efficient?**

   Every call to findNextCell() is expensive as it checks isValid() and is used every time this function is called recursively so for every call isValid() is called at the least twice. To make it more efficient I would use a min heap allocated in the program heap with the least options on top and the most on bottom with a custom struct with the row and column of the cell. The cost of faster solving is more memory.

4. **Can you make this a generalized solution, meaning board that can solve any NxN grid where N is a square number? Can you briefly share your ideas?**

   In this solution, I count isValid() calls as 1 and therefore in the worst case of no cells filled O(9(n^2)). 

5. **Did this project challenge and motivate you? We would appreciate your feedback on your experience. Feel free to share what you learned, what aspects of the project you found most engaging or challenging, and any suggestions you have for improving future projects. Your insights are valuable in helping us enhance future learning experiences.**

   For me, this project was a little challenging. Writing the code was really straight forward since the todo was thorough but writing the docstring and the program flowchart were very time-consuming and not something I'm used to when programming. 

---

## Closing Thoughts

I think if we were required to make the efficient solver actually efficient using a minimum heap I think the project would be more interesting and engaging implementing a very technical data structure. Other than that, I really enjoyed working on this project in my freetime.

---
