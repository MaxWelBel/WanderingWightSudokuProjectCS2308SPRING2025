/**
* @file generator.h
 * @brief Function prototypes for generating random solvable Sudoku boards.
 *
 * This header defines functions to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve and generate a complete Sudoku board.
 * - Randomly delete cells to create a solvable puzzle.
 * - Generate a complete Sudoku puzzle with a specific number of empty cells.
 *
 * Detailed function descriptions and parameters are provided below.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>

/**
 * @brief Dynamically allocates and returns a sudoku board.
 *
 * @return A pointer to the dynamically allocated sudoku board.
 */
int** getEmptyBoard();

/**
  * @brief Creates and returns a shuffled vector of the values 1-9.
  *
  * Fills the int vector in ascending order from 1 to 9.
  * Creates mersenne-twister engine seeded with random_device for more random results.
  * Uses the std::shuffle function defined in <algorithm> with the vector iterators
  * and mersenne-twister engine
  *
  * @return Integer vector with the shuffled values.
  */
std::vector<int> getShuffledVector();

/**
  * @brief Fills a sudoku board boxes diagonally.
  *
  * Uses getShuffledVector() and populates 3 boxes diagonally such that
  * the top-most-left-most box is full, the center box is full, and
  * the right-most-bottom-most box is filled.
  *
  * @param BOARD Pointer to an empty 9x9 Sudoku board.
  */
void fillBoardWithIndependentBox(int** BOARD);

/**
  * @brief Deletes n number of items from sudoku board.
  *
  * Ensures BOARD exists and that N is between 1 and 81
  * Uses mersenne-twister engine seeded with random_device as a
  * parameter for a std::uniform_int_distribution to randomly select
  * a row and a column for a value to delete.
  * Ensures that the value to be deleted isn't already 0.
  *
  * @param BOARD Pointer to a 9x9 sudoku board.
  * @param n The number of items to delete.
  */
void deleteRandomItems(int** BOARD, const int& n);

/**
  * @brief Creates a solvable 9x9 sudoku board with a specified number of missing values.
  *
  * Creates an empty board using getEmptyBoard().
  * Populates the boxes diagonally with values using fillBoardWithIndependentBox().
  * Solves the board completely using solveBoard() defined in sudoku.h.
  * Removes a number of items from the board using deleteRandomItems() parameterized
  * with empty_boxes.
  *
  * @param empty_boxes Integer number of how many items to remove
  * @return Pointer to the sudoku board
  */
int** generateBoard(const int& empty_boxes);

#endif // GENERATOR_H
