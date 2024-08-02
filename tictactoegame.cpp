#include <iostream>
#include <vector>
using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if there is a winner
char checkWinner(vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // No winner yet
    return ' ';
}

// Function to check if the board is full (tie condition)
bool isBoardFull(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 Tic-Tac-Toe board
    bool player1Turn = true;
    bool gameEnd = false;
    
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    
    while (!gameEnd) {
        printBoard(board);
        
        // Determine current player
        char currentPlayer = (player1Turn) ? 'X' : 'O';
        int row, col;
        
        // Get player input
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        
        // Adjust row and column to match array indexing (0-based index)
        row--; // Convert to 0-based index
        col--; // Convert to 0-based index
        
        // Check if the input is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        
        // Update the board
        board[row][col] = currentPlayer;
        
        // Check if there is a winner
        char winner = checkWinner(board);
        if (winner != ' ') {
            printBoard(board);
            cout << "Player " << winner << " wins!" << endl;
            gameEnd = true;
        } else if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            gameEnd = true;
        } else {
            // Switch to the other player's turn
            player1Turn = !player1Turn;
        }
    }
    
    return 0;
}
