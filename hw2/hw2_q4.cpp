#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// check if number is already selected
bool isSelected(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

// select random winners
void selectWinners(int winners[], int numWinners, int totalFinalists) {
    int count = 0;
    
    while (count < numWinners) {
        int num = rand() % totalFinalists + 1;  // random number 1-25
        
        if (!isSelected(winners, count, num)) {
            winners[count] = num;
            count++;
        }
    }
}

int main() {
    const int NUM_PRIZES = 4;
    const int TOTAL_FINALISTS = 25;
    int winners[NUM_PRIZES];
    
    // seed random
    srand(time(0));
    
    cout << "========== Prize Drawing ==========" << endl;
    cout << "Total finalists: " << TOTAL_FINALISTS << endl;
    cout << "Number of prizes: " << NUM_PRIZES << endl;
    cout << "\nSelecting winners..." << endl;
    
    // select winners
    selectWinners(winners, NUM_PRIZES, TOTAL_FINALISTS);
    
    // output results
    cout << "\nThe winners are finalists:" << endl;
    for (int i = 0; i < NUM_PRIZES; i++) {
        cout << "  Winner " << i + 1 << ": Finalist #" << winners[i] << endl;
    }
    cout << "\n===================================\n" << endl;
    
    return 0;
}
