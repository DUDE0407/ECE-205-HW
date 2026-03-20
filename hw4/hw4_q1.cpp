#include <iostream>
#include <windows.h>  // For setting console output encoding
using namespace std;

const int MAX_SIZE = 1000;  // Maximum array size
const int MAX_BINS = 100;   // Maximum number of histogram bins

// Read size non-negative integers from user into arr
void getInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> arr[i];
        while (arr[i] < 0) {
            cout << "Value must be non-negative. Re-enter: ";
            cin >> arr[i];
        }
    }
}

// Find the maximum value in the array (to determine number of bins)
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

int calculateHistogram(int arr[], int size, int hist[]) {
    int numBins = findMax(arr, size) / 10 + 1;
    for (int i = 0; i < numBins; i++) hist[i] = 0;
    for (int i = 0; i < size; i++)
        hist[arr[i] / 10]++;
    return numBins;
}

void printHistogram(int hist[], int numBins) {
    cout << "\n--- Histogram ---\n";
    for (int i = 0; i < numBins; i++) {
        cout << "Bin " << i + 1 << " [" << i * 10 << " - " << i * 10 + 9 << "]: ";
        for (int j = 0; j < hist[i]; j++) cout << "█";
        cout << " (" << hist[i] << ")\n";
    }
}

int main() {
    SetConsoleOutputCP(65001);
    int size;
    cout << "Enter number of integers: ";
    cin >> size;
    while (size <= 0) {
        cout << "Size must be positive. Re-enter: ";
        cin >> size;
    }

    int arr[MAX_SIZE];  // Store user input integers
    int hist[MAX_BINS]; // Store counts for each bin

    getInput(arr, size);
    int numBins = calculateHistogram(arr, size, hist);
    printHistogram(hist, numBins);

    return 0;
}
