#include <iostream>
#include <vector>
using namespace std;

// Returns the bin index for the given value (bins are 0-9, 10-19, etc.)
int getBin(int value) {
    return value / 10;
}

// Builds a histogram from the input data
void buildHistogram(const vector<int>& data, vector<int>& histogram) {
    for (int val : data) {
        int bin = getBin(val);
        if (bin >= (int)histogram.size()) {
            histogram.resize(bin + 1, 0);
        }
        histogram[bin]++;
    }
}

// Prints the histogram to the console
void printHistogram(const vector<int>& histogram) {
    cout << "\n--- Histogram ---\n";
    for (int i = 0; i < (int)histogram.size(); i++) {
        int low  = i * 10;
        int high = low + 9;
        cout << "[" << low << " - " << high << "] : " << histogram[i] << "\n";
    }
}

// Main function to read input and generate histogram
int main() {
    vector<int> data;
    vector<int> histogram;

    cout << "Enter integers (negative number to stop):\n";

    int input;

    while (cin >> input && input >= 0) {
        data.push_back(input);
    }

    if (data.empty()) {
        cout << "No data entered.\n";
        return 0;
    }

    buildHistogram(data, histogram);
    printHistogram(histogram);

    return 0;
}
