#include <bits/stdc++.h>

using namespace std;

// Array to store the current state of the board
char board[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

// Function to check the winner of the game
int checkWin() {
    // Check rows for a win
    if (board[0] == board[1] && board[1] == board[2]) {
        return board[0] == 'X' ? 1 : 2;
    }
    if (board[3] == board[4] && board[4] == board[5]) {
        return board[3] == 'X' ? 1 : 2;
    }
    if (board[6] == board[7] && board[7] == board[8]) {
        return board[6] == 'X' ? 1 : 2;
    }

    // Check columns for a win
    if (board[0] == board[3] && board[3] == board[6]) {
        return board[0] == 'X' ? 1 : 2;
    }
    if (board[1] == board[4] && board[4] == board[7]) {
        return board[1] == 'X' ? 1 : 2;
    }
    if (board[2] == board[5] && board[5] == board[8]) {
        return board[2] == 'X' ? 1 : 2;
    }

    // Check diagonals for a win
    if (board[0] == board[4] && board[4] == board[8]) {
        return board[0] == 'X' ? 1 : 2;
    }
    if (board[2] == board[4] && board[4] == board[6]) {
        return board[2] == 'X' ? 1 : 2;
    }

    // No winner yet
    return 0;
}

// Function to mark the board with the player's symbol
void markBoard(int player, int box) {
    if (player == 1) {
        board[box] = 'X';
    } else {
        board[box] = 'O';
    }
}

// Function to display the current state of the board
void displayBoard() {
    for (int i = 0; i < 9; i++) {
        cout << board[i] << "\t";
        if (i == 2 || i == 5 || i == 8) {
            cout << "\n";
        }
    }
}

// Function to check if a box is already taken
bool isBoxTaken(int box) {
    return board[box] == 'X' || board[box] == 'O';
}

int main() {
    int player1 = 1, player2 = 2;
    int box, result = 0, isGameOver = 0;

    for (int i = 1; i < 5; i++) {
        // Player 1's turn
        cout << "\nPlayer " << player1 << ", enter the box number: ";
        cin >> box;

        // Check if the box is already taken
        while (isBoxTaken(box)) {
            cout << "Box already taken. Please enter another box number: ";
            cin >> box;
        }

        markBoard(player1, box);
        displayBoard();

        // Check if Player 1 wins
        result = checkWin();
        if (result == 1) {
            cout << "\nCongratulations! Player " << player1 << " has won.\n";
            isGameOver = 1;
            break;
        } else if (result == 2) {
            cout << "\nCongratulations! Player " << player2 << " has won.\n";
            isGameOver = 1;
            break;
        }

        // Player 2's turn
        cout << "\nPlayer " << player2 << ", enter the box number: ";
        cin >> box;

        // Check if the box is already taken
        while (isBoxTaken(box)) {
            cout << "Box already taken. Please enter another box number: ";
            cin >> box;
        }

        markBoard(player2, box);
        displayBoard();

        // Check if Player 2 wins
        result = checkWin();
        if (result == 1) {
            cout << "\nCongratulations! Player " << player1 << " has won.\n";
            isGameOver = 1;
            break;
        } else if (result == 2) {
            cout << "\nCongratulations! Player " << player2 << " has won.\n";
            isGameOver = 1;
            break;
        }
    }

    // Check if the game is a draw
    if (isGameOver == 0) {
        cout << "\nSorry, the game is a draw.\n";
    }

    return 0;
}
