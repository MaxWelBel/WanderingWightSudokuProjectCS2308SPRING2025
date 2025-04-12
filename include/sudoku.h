/**
 * @file sudoku.h
 * @brief Core Sudoku solving and board generation functions.
 *
 * This header file declares functions essential for solving Sudoku puzzles
 * and validating board states. It includes:
 * - A backtracking Sudoku solver.
 * - A cell validation function to ensure valid number placement.
 * - A board generation stub for creating Sudoku puzzles.
 *
 * All functions operate on dynamically allocated 9x9 Sudoku boards
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H

#include <iostream>

/**
  * @brief Checks if a number is valid for a sudoku board.
  *
  * Checks if the value exists in the row or column.
  * Checks if the value exists in the 3x3 box the value
  * is located in.
  * Returns false if both of the above are not true.
  *
  * @param BOARD 9x9 sudoku board.
  * @param r The row of the value.
  * @param c The column of the value.
  * @param k The value being inserted.
  * @return True if the number can be placed in the position.
  */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
  * @brief Solves the sudoku board using the simple backtracking method.
  *
  * This is a recursive function.
  *
  * Returns true if we've reached past the end of the board.
  * Recursively calls to next row if reached past the end of the current row.
  * Recursively calls to next cell if the cell is already full.
  * Tries to place numbers 1-9 in the cell using the isValid() function.
  * If it succeeds it will keep moving onto the next cell until no
  * numbers are valid and returns false to trigger backtracking.
  *
  * @param BOARD 9x9 Sudoku Board.
  * @param r The row to start on.
  * @param c The column to start on.
  * @return True if the board can be solved and is solved
  */
bool solveBoard(int** BOARD, const int& r=0, const int& c=0);

// ========================= Efficient Solutions ==========================


/**
  * @brief Finds and returns the cell with the least number of options
  *
  * Iterates through the board until a cell is found with 1 option.
  * If there is none, will return the cell with the first cell
  * with the least amount of options.
  *
  * @param BOARD 2D sudoku board.
  * @return Tuple containing cell row, cell column, and number of options valid for the cell.
  */
std::tuple<int, int, int> findNextCell(int** BOARD);


/**
  * @brief
  *
  * @return True if the board is solved.
  */
bool solveBoardEfficient(int** BOARD);

/**
  * @brief Solves Sudoku board with MRV or normal backtracking method.
  *
  * Uses findNextCell() to implement the Minimum-Remaining Value heuristic to solve the board.
  * Implementation is the same as solveBoard() but with this heuristic.
  *
  * @param board 2D sudoku board.
  * @param efficient Whether to use the efficient solver.
  * @return call to either solveBoard() or solveBoardEfficient() depending on value of efficient
  */
bool solve(int** board, const bool& efficient = false);

#endif //SUDOKUPROJECT_SUDOKU_H