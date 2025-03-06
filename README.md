# Tower-of-Hanoi

Here is a sample README file for the hw4a.c code:

Tower of Hanoi

This project implements the Tower of Hanoi puzzle using C programming language.

Description

The Tower of Hanoi is a classic puzzle involving three pegs and a number of disks of different sizes. The objective is to move all the disks from the first peg to the third peg following these rules:

Only one disk can be moved at a time.

A disk can only be placed on top of a larger disk or an empty peg.

Files

hw4a.c: The main C source file containing the implementation of the Tower of Hanoi solution.

Functions

void move(int n, int start, int end, char** A, char** B, char** C, int const_n): Moves a disk from one peg to another.

int find_lvl(int const_n, char** P): Finds the level of a peg.

void tower(int n, int start, int end, int ath, char* A[], char*B[], char*C[], int const_n): Recursively solves the Tower of Hanoi puzzle.

Usage

Compile the hw4a.c file using a C compiler:
gcc hw4a.c -o hanoi

Run the executable and input the number of disks:
./hanoi
