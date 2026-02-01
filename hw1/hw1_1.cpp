#include <iostream>
using namespace std;
#include <iomanip>

int main() {
    int totalSeconds;
    cin >> totalSeconds;

    int hours = totalSeconds / 3600;
    int remaining = totalSeconds % 3600;
    int minutes = remaining / 60;
    int seconds = remaining % 60;

    cout << hours << " hours," << minutes << " minutes," << seconds << " seconds" << "\n" <<endl;

    cout << fixed << setprecision (4);
    cout << totalSeconds / 3600.0 << " hours" << "\n";
    cout << totalSeconds / 60.0 << " minutes" << "\n";
    
    return 0;
}
