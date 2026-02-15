#include <iostream>
#include <iomanip>
using namespace std;

// calculate hat size
double calcHat(double weight, double height) {
    return 2.9 * weight / height;
}

// calculate jacket size
double calcJacket(double height, double weight, int age) {
    double base = height * weight / 288.0;
    
    // adjust for age over 30
    if (age > 30) {
        int years = (age - 30) / 10;  // only full 10 years
        base += years * (1.0 / 8.0);
    }
    
    return base;
}

// calculate waist size
double calcWaist(double weight, int age) {
    double base = weight / 5.7;
    
    // adjust for age over 28
    if (age > 28) {
        int years = (age - 28) / 2;  // only full 2 years
        base += years * (1.0 / 10.0);
    }
    
    return base;
}

int main() {
    double height, weight;
    int age;
    
    cout << "========== Clothing Size Calculator ==========" << endl;
    cout << "Enter your height (inches): ";
    cin >> height;
    
    cout << "Enter your weight (pounds): ";
    cin >> weight;
    
    cout << "Enter your age (years): ";
    cin >> age;
    
    // calculate sizes
    double hatSize = calcHat(weight, height);
    double jacketSize = calcJacket(height, weight, age);
    double waistSize = calcWaist(weight, age);
    
    // output results
    cout << "\n========== Your Clothing Sizes ==========" << endl;
    cout << fixed << setprecision(2);
    cout << "Hat size: " << hatSize << " inches" << endl;
    cout << "Jacket size: " << jacketSize << " inches" << endl;
    cout << "Waist size: " << waistSize << " inches" << endl;
    cout << "==========================================\n" << endl;
    
    return 0;
}
