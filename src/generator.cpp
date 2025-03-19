//
// Created by Keshav Bhandari on 2/19/25.
//

/**
 * @file generator.cpp
 * @brief Implementation of functions to generate random solvable Sudoku boards.
 *
 * This file should contain logic to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve the filled board to complete it.
 * - Randomly remove cells to create solvable Sudoku puzzles.
 *
 * - Replace the dummy code section with appropriate logic
 *
 * You should provide detailed function descriptions in the corresponding header file.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */


#include "../include/generator.h"
#include "../include/sudoku.h"
#include "../include/sudoku_io.h"
#include <random>
#include <bitset>
#include <algorithm>

using namespace std;

int** getEmptyBoard() {
    int** board = new int*[9];
    for(int i = 0; i < 9; i++){
        board[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    } //Initialization ends here
    return board;
}

std::vector<int> getShuffledVector() {
    std::vector<int> vect {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::random_device randomDevice;
    std::mt19937 merTwist(randomDevice()); // Seed for mersenne twister to get more true random numbers

    std::shuffle(vect.begin(), vect.end(), merTwist);
    return vect;
}

void fillBoardWithIndependentBox(int** BOARD) {
    for (int box = 0; box < 9; box+=3) {
        std::vector<int> numbers = getShuffledVector();
        for (int offset = 0; offset < 9; offset++) {
            BOARD[box + (offset/3)][box + (offset%3)] = numbers[offset];
        }
    }
}

// Function to randomly delete 'n' items from a 9x9 Sudoku board using bitsets
void deleteRandomItems(int** BOARD, const int& n) {
    if (BOARD != nullptr && (n >= 1 && n <= 81)) {
        std::random_device randomDevice;
        std::mt19937 merTwist(randomDevice());
        std::uniform_int_distribution<int> randInt(0, 8);

        int remaining = n;
        while (remaining > 0) {
            int row = randInt(merTwist);
            int col = randInt(merTwist);
            if (BOARD[row][col] == 0) continue; // Don't nullify what is already null
            BOARD[row][col] = 0;
            remaining--;
        }
    }
}

int** generateBoard(const int& empty_boxes){
    int** BOARD = getEmptyBoard();
    fillBoardWithIndependentBox(BOARD);
    solveBoard(BOARD);
    deleteRandomItems(BOARD, empty_boxes);

    return BOARD;
}