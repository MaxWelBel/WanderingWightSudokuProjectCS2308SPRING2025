# Sudoku Solver Project
The purpose of this project was to create a more efficient sudoku solver. 

## Key Features
- Sudoku problem generation with specifiable amount of boxes missing
- Saving of sudoku puzzles to filesystem
- Reading of sudoku puzzles to filesystem
- Comparing sudoku solvers 

## Summary

The original sudoku solver uses a very simplistic guess-and-check backtracking method. It would do this by placing a number in an empty cell, check to make sure that the number placed in that cell was a valid option by checking the row that it is on, the colum that it is on, and the 3x3 box that it is in. 

The "efficient" sudoku solver uses the original framework with the minimum-remaining value heuristic. Instead of picking the first empty cell, it finds the first empty cell with the least amount of valid options available. 

In theory, the efficient sudoku solver should be faster than the original but we are forgetting that computers cannot infer our meaning. When solving "efficiently" we are actually redoing the work we did to find the least amount of options every time. The most simple solution would be to have some sort of system that, instead of doing the work over it would keep a priority list of the cells with the least amount of options. One such abstract data structure would be a minimum heap. Unfortunately, this was outside the scope of required work so it was not done so.
