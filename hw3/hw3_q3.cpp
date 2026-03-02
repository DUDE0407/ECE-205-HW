#include <iostream>
using namespace std;

// function to calculate minutes between two times
int calcMinutes(int startTime, int endTime) {
    int startHours = startTime / 100;
    int startMins = startTime % 100;
    int endHours = endTime / 100;
    int endMins = endTime % 100;
    
    // convert to total minutes from midnight
    int startTotal = startHours * 60 + startMins;
    int endTotal = endHours * 60 + endMins;
    
    int diff;
    
    // check if end time is next day
    if (endTotal < startTotal) {
        // end time is next day
        diff = (24 * 60 - startTotal) + endTotal;
    } else {
        diff = endTotal - startTotal;
    }
    
    return diff;
}

int main() {
    int start, end;
    
    cout << "Time Interval Calculator" << endl;
    cout << "========================" << endl;
    cout << "Enter start time (24-hour format, e.g., 2300): ";
    cin >> start;
    
    cout << "Enter end time (24-hour format, e.g., 0600): ";
    cin >> end;
    
    // validate input
    if (start < 0 || start > 2359 || end < 0 || end > 2359) {
        cout << "Invalid time format!" << endl;
        return 1;
    }
    
    int minutes = calcMinutes(start, end);
    
    cout << "\nTime interval: " << minutes << " minutes" << endl;
    
    return 0;
}
