#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void printBoard(const vector<vector<char> > &board);
bool makeMove(vector<vector<char> > &board, int row, int col, char player);
bool checkWin(const vector<vector<char> > &board, char player);
bool isBoardFull(const vector<vector<char> > &board);

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' ')); // 3x3 Tic Tac Toe board
    int row, col;
    char currentPlayer = 'X';

    cout << "Welcome to Tic Tac Toe!\n";

    do {
        // Display the current state of the board
        printBoard(board);

        // Get the current player's move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Make the move if valid
        if (makeMove(board, row, col, currentPlayer)) {
            // Check if the current player wins
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check if the board is full (a tie)
            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!\n";
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again.\n";
        }

    } while (true);

    return 0;
}

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char> > &board) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to make a move on the board
bool makeMove(vector<vector<char> > &board, int row, int col, char player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false; // Invalid move
    }

    board[row][col] = player;
    return true;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char> > &board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }

    // Diagonal wins
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Top-left to bottom-right diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Top-right to bottom-left diagonal
    }

    return false;
}


// Function to check if the board is full (a tie)
bool isBoardFull(const vector<vector<char> > &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There is an empty space, the board is not full
            }
        }
    }
    return true; // The board is full
}
