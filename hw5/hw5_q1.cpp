#include <iostream>
using namespace std;

class BicycleSpeedometer {
private:
    double distance;
    double time;

public:
    BicycleSpeedometer() : distance(0), time(0) {}

    void setDistance(double d) { distance = d; }
    void setTime(double t) { time = t; }

    double getDistance() const { return distance; }
    double getTime() const { return time; }

    double computeAverageSpeed() const {
        if (time == 0) return 0;
        return distance / (time / 60.0);
    }
};

int main() {
    BicycleSpeedometer speedometer;
    double d, t;

    cout << "Enter distance traveled (miles): ";
    cin >> d;
    speedometer.setDistance(d);

    cout << "Enter time taken (minutes): ";
    cin >> t;
    speedometer.setTime(t);

    cout << "Average speed: " << speedometer.computeAverageSpeed() << " miles per hour" << endl;

    return 0;
}
