#include <iostream>
#include <vector>
using namespace std;

// Removes duplicate characters from the vector, keeping the first occurrence
void deleteRepeatedChars(vector<char>& myVector) {
    for (int i = 0; i < (int)myVector.size(); i++) {
        for (int j = i + 1; j < (int)myVector.size(); ) {
            if (myVector[j] == myVector[i]) {
                for (int k = j; k < (int)myVector.size() - 1; k++) {
                    myVector[k] = myVector[k + 1];
                }
                myVector.pop_back();
            } else {
                j++;
            }
        }
    }
}

// Sorts the vector in descending order using selection sort
void selectionSort(vector<char>& myVector) {
    int n = myVector.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (myVector[j] > myVector[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            char temp       = myVector[i];
            myVector[i]     = myVector[maxIdx];
            myVector[maxIdx] = temp;
        }
    }
}

// Main function to read input, remove duplicates, and sort
int main() {
    vector<char> myVector;

    cout << "Enter characters one at a time (enter '0' to stop):\n";

    char input;
    while (cin >> input && input != '0') {
        myVector.push_back(input);
    }

    if (myVector.empty()) {
        cout << "No characters entered.\n";
        return 0;
    }

    cout << "\nOriginal: ";
    for (char c : myVector) cout << c << " ";

    deleteRepeatedChars(myVector);
    cout << "\nAfter removing duplicates: ";
    for (char c : myVector) cout << c << " ";

    selectionSort(myVector);
    cout << "\nAfter sorting (z to a): ";
    for (char c : myVector) cout << c << " ";
    cout << "\n";

    return 0;
}
