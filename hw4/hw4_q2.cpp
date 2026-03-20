#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_JUDGES = 7;

// Input and validate scores from 7 judges (range 0.0 - 10.0)
void getScores(double scores[]) {
    for (int i = 0; i < NUM_JUDGES; i++) {
        cout << "Enter score for judge " << i + 1 << " (0.0 - 10.0): ";
        cin >> scores[i];
        while (scores[i] < 0.0 || scores[i] > 10.0) {
            cout << "Score must be between 0 and 10. Re-enter: ";
            cin >> scores[i];
        }
    }
}

// Find the minimum value in the array
double findMin(double arr[], int size) {
    double min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

// Find the maximum value in the array
double findMax(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

// Calculate final score: remove highest and lowest, sum remaining * difficulty * 0.6
double calculateDiverScore(double scores[], double difficulty) {
    double minScore = findMin(scores, NUM_JUDGES);
    double maxScore = findMax(scores, NUM_JUDGES);
    double sum = 0.0;
    bool minDropped = false, maxDropped = false;

    for (int i = 0; i < NUM_JUDGES; i++) {
        if (!minDropped && scores[i] == minScore) { minDropped = true; continue; }
        if (!maxDropped && scores[i] == maxScore) { maxDropped = true; continue; }
        sum += scores[i];
    }
    return sum * difficulty * 0.6;
}

int main() {
    double difficulty;
    cout << "Enter degree of difficulty (1.2 - 3.8): ";
    cin >> difficulty;
    while (difficulty < 1.2 || difficulty > 3.8) {
        cout << "Difficulty must be between 1.2 and 3.8. Re-enter: ";
        cin >> difficulty;
    }

    double scores[NUM_JUDGES];
    getScores(scores);

    double finalScore = calculateDiverScore(scores, difficulty);

    cout << fixed << setprecision(2);
    cout << "\n--- Results ---\n";
    cout << "Degree of Difficulty: " << difficulty << "\n";
    cout << "Scores entered:       ";
    for (int i = 0; i < NUM_JUDGES; i++) cout << scores[i] << " ";
    cout << "\nMin score dropped:    " << findMin(scores, NUM_JUDGES) << "\n";
    cout << "Max score dropped:    " << findMax(scores, NUM_JUDGES) << "\n";
    cout << "Final Diver Score:    " << finalScore << "\n";

    return 0;
}
