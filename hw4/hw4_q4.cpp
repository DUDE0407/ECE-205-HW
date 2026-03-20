#include <iostream>
using namespace std;

void initBoard(char board[][3]) {
    int num = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '0' + num++;
}

// Display current board state
void displayBoard(char board[][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2];
        if (i < 2) cout << "\n---+---+---";
        cout << "\n";
    }
    cout << "\n";
}

// Check if the specified player has won
bool checkWin(char board[][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Check draw condition: no winner and board is full
bool isBoardFull(char board[][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

// Make a move: return true if successful, false if invalid or occupied
bool makeMove(char board[][3], int pos, char player) {
    if (pos < 1 || pos > 9) return false;
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') return false;
    board[row][col] = player;
    return true;
}

int main() {
    char board[3][3];
    initBoard(board);

    cout << "=== Tic-Tac-Toe ===\n";
    cout << "Positions are numbered 1-9 as shown:\n";
    displayBoard(board);

    char players[] = {'X', 'O'};
    int turn = 0;

    while (true) {
        char currentPlayer = players[turn % 2];
        int pos;
        bool valid = false;

        while (!valid) {
            cout << "Player " << currentPlayer << ", enter position (1-9): ";
            cin >> pos;
            valid = makeMove(board, pos, currentPlayer);
            if (!valid) cout << "Invalid or already taken. Try again.\n";
        }

        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "*** Player " << currentPlayer << " wins! Congratulations! ***\n";
            break;
        }
        if (isBoardFull(board)) {
            cout << "*** It's a draw! Well played! ***\n";
            break;
        }
        turn++;
    }

    return 0;
}
