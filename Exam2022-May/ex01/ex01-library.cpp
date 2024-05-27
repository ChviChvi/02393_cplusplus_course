#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int m, unsigned int n) {

    /**
     * The function createChessboard needs to allocate a 2D array of Square structures,
     * each initialized to have piece as none and team as nobody.
    **/
    // Allocate an array of pointers to arrays of Squares
    Square **chessboard = new Square*[m];

    // Allocate each row and initialize the squares
    for (unsigned int i = 0; i < m; ++i) {
        chessboard[i] = new Square[n];
        for (unsigned int j = 0; j < n; ++j) {
            // Initialize each square to have no piece and nobody as the team
            chessboard[i][j].piece = none;
            chessboard[i][j].team = nobody;
        }
    }

    return chessboard;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c,
                       unsigned int m, unsigned int n) {


    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (c[i][j].piece == none) {
                cout << "_";
            } else {
                if (c[i][j].piece == king) {
                    cout << (c[i][j].team == black ? "K" : "k");
                } else if (c[i][j].piece == queen) {
                    cout << (c[i][j].team == black ? "Q" : "q");
                }
            }
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int m, unsigned int n,
          int r1, int c1, int r2, int c2) {
    // Replace the following with your code

    // Check if the starting position has a piece
    if (c[r1][c1].piece == none) {
        return false;
    }

    // Check if the destination is different from the source
    if (r1 == r2 && c1 == c2) {
        return false;
    }

    // Check if the destination is not occupied by the same team
    if (c[r2][c2].team == c[r1][c1].team) {
        return false;
    }

    // Get the type of piece and team
    Piece piece = c[r1][c1].piece;
    Team team = c[r1][c1].team;

    // Validate the move according to the piece type
    bool validMove = false;
    if (piece == king) {
        // King moves one square in any direction
        validMove = (abs(r1 - r2) <= 1 && abs(c1 - c2) <= 1);
    } else if (piece == queen) {
        // Queen moves any number of squares horizontally, vertically, or diagonally
        validMove = (r1 == r2 || c1 == c2 || abs(r1 - r2) == abs(c1 - c2));
    }

    // If the move is valid, perform the move
    if (validMove) {
        // Capture the opponent's piece if present
        c[r2][c2] = {piece, team};
        // Empty the original square
        c[r1][c1] = {none, nobody};
        return true;
    } else {
        return false;
    }
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int m, unsigned int n,
                int row, int col) {
    // Replace the following with your code

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if(move(c, m, n, i, j, row, col)){
                return true;
            }
        }
    }


    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] c[i];
    }
    delete[] c;
}
