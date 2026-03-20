#include <iostream>
#include <cctype>
using namespace std;

const int ROWS = 10;
const int COLS = 4;
const char COL_LABELS[] = {'A', 'B', 'C', 'D'};  // Column labels

// Initialize all seats to available
void initSeats(char seats[][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = COL_LABELS[j];
}

// Display current seat map
void displaySeats(char seats[][COLS]) {
    cout << "\n--- Seat Map ---\n";
    for (int i = 0; i < ROWS; i++) {
        cout << (i + 1 < 10 ? " " : "") << i + 1 << " ";
        cout << seats[i][0] << " " << seats[i][1] << "  "
             << seats[i][2] << " " << seats[i][3] << "\n";
    }
    cout << "\n";
}

// Check if all seats are occupied
bool isFull(char seats[][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] != 'X') return false;
    return true;
}

// Convert column letter to index (A=0, B=1, C=2, D=3), return -1 for invalid
int colIndex(char c) {
    c = toupper(c);
    for (int i = 0; i < COLS; i++)
        if (COL_LABELS[i] == c) return i;
    return -1;
}

// Prompt user for seat selection and assign, loop on invalid input
void assignSeat(char seats[][COLS]) {
    int row;
    char col;
    while (true) {
        cout << "Enter desired seat (e.g. 3 B): ";
        cin >> row >> col;
        col = toupper(col);
        int cIdx = colIndex(col);

        if (row < 1 || row > ROWS || cIdx == -1) {
            cout << "Invalid entry. Row must be 1-10 and column A-D.\n";
            continue;
        }
        if (seats[row - 1][cIdx] == 'X') {
            cout << "Seat " << row << col << " is already taken. Try another seat.\n";
            continue;
        }
        seats[row - 1][cIdx] = 'X';
        cout << "Seat " << row << col << " successfully assigned!\n";
        break;
    }
}

int main() {
    char seats[ROWS][COLS];
    initSeats(seats);

    char choice;
    do {
        displaySeats(seats);
        if (isFull(seats)) {
            cout << "All seats are taken. Boarding complete!\n";
            break;
        }
        assignSeat(seats);
        displaySeats(seats);
        cout << "Do you want to assign another seat? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y' && !isFull(seats));

    cout << "Thank you!\n";
    return 0;
}
