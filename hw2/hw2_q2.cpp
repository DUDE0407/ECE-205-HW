#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

// calculate average
double calcAvg(double scores[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    return sum / n;
}

// calculate standard deviation
double calcStdDev(double scores[], int n, double avg) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double diff = scores[i] - avg;
        sum += pow(diff, 2);
    }
    double variance = sum / n;
    return sqrt(variance);
}

int main() {
    const int NUM_SCORES = 5;
    double scores[NUM_SCORES];
    
    // read scores from file
    ifstream inFile("scores.txt");
    if (!inFile) {
        cout << "Error: Cannot open scores.txt" << endl;
        return 1;
    }
    
    cout << "Reading scores from scores.txt..." << endl;
    for (int i = 0; i < NUM_SCORES; i++) {
        inFile >> scores[i];
        cout << "Score " << i + 1 << ": " << scores[i] << endl;
    }
    inFile.close();
    
    // calculate average and std deviation
    double avg = calcAvg(scores, NUM_SCORES);
    double stdDev = calcStdDev(scores, NUM_SCORES, avg);
    
    // output to console
    cout << "\n========== Results ==========" << endl;
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << endl;
    cout << "Standard Deviation: " << stdDev << endl;
    cout << "============================\n" << endl;
    
    // output to file
    ofstream outFile("output.txt");
    if (!outFile) {
        cout << "Error: Cannot create output.txt" << endl;
        return 1;
    }
    
    outFile << fixed << setprecision(2);
    outFile << "Average: " << avg << endl;
    outFile << "Standard Deviation: " << stdDev << endl;
    outFile.close();
    
    cout << "Results saved to output.txt" << endl;
    
    return 0;
}
