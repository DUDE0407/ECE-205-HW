#include <iostream>
using namespace std;

// input function
void getTime(int &hours, int &minutes) {
    cout << "Enter time in 24-hour format (HH:MM)" << endl;
    cout << "First, enter hours (0-23): ";
    cin >> hours;
    cout << "Then, enter minutes (0-59): ";
    cin >> minutes;
}

// conversion function
void convertTo12Hour(int hours24, int minutes, int &hours12, char &period) {
    if (hours24 == 0) {
        hours12 = 12;
        period = 'A';  // AM
    } else if (hours24 < 12) {
        hours12 = hours24;
        period = 'A';  // AM
    } else if (hours24 == 12) {
        hours12 = 12;
        period = 'P';  // PM
    } else {
        hours12 = hours24 - 12;
        period = 'P';  // PM
    }
}

// output function
void displayTime(int hours, int minutes, char period) {
    cout << "12-hour format: " << hours << ":";
    if (minutes < 10) {
        cout << "0";
    }
    cout << minutes << " ";
    if (period == 'A') {
        cout << "AM" << endl;
    } else {
        cout << "PM" << endl;
    }
}

int main() {
    int h24, min, h12;
    char period, choice;
    
    cout << "24-Hour to 12-Hour Time Converter" << endl;
    cout << "==================================\n" << endl;
    
    while (true) {
        getTime(h24, min);
        
        // validate input
        if (h24 < 0 || h24 > 23 || min < 0 || min > 59) {
            cout << "Invalid time! Try again." << endl;
            continue;
        }
        
        convertTo12Hour(h24, min, h12, period);
        displayTime(h12, min, period);
        
        cout << "\nConvert another time? (y/n): ";
        cin >> choice;
        
        if (choice == 'n' || choice == 'N') {
            cout << "Program ended." << endl;
            break;
        }
        
        cout << endl;
    }
    
    return 0;
}
