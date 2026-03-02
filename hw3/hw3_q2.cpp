#include <iostream>
#include <cmath>
using namespace std;

// function to calculate area and perimeter
void calcTriangle(double a, double b, double c, double &area, double &perimeter) {
    // check if sides can form a valid triangle
    if (a + b <= c || a + c <= b || b + c <= a || a <= 0 || b <= 0 || c <= 0) {
        area = 0;
        perimeter = 0;
        return;
    }
    
    // calculate perimeter
    perimeter = a + b + c;
    
    // calculate semi-perimeter
    double s = perimeter / 2.0;
    
    area = sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double side1, side2, side3;
    double area, perimeter;
    
    cout << "Triangle Area and Perimeter Calculator" << endl;
    cout << "=======================================" << endl;
    
    cout << "Enter length of side 1: ";
    cin >> side1;
    
    cout << "Enter length of side 2: ";
    cin >> side2;
    
    cout << "Enter length of side 3: ";
    cin >> side3;
    
    calcTriangle(side1, side2, side3, area, perimeter);
    
    cout << "\nResults:" << endl;
    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;
    
    if (area == 0 && perimeter == 0) {
        cout << "(Invalid triangle - these sides cannot form a triangle)" << endl;
    }
    
    return 0;
}
