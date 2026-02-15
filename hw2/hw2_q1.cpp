#include <iostream>
#include <cmath>
using namespace std;

const double G = 6.673e-8;

// calculate force
double calcForce(double m1, double m2, double d) {
    double mass1 = m1 * 1000;  // kg to g
    double mass2 = m2 * 1000;
    
    double dist = pow(d, 2);
    
    double F = (G * mass1 * mass2) / dist;
    
    return F;
}

int main() {
    char ch;
    
    do {
        double m1, m2, dist;
        
        cout << "\n==================== Gravitational Force Calculator ====================" << endl;
        cout << "Enter mass of first object (kg): ";
        cin >> m1;
        
        cout << "Enter mass of second object (kg): ";
        cin >> m2;
        
        cout << "Enter distance between objects (cm): ";
        cin >> dist;
        
        double result = calcForce(m1, m2, dist);
        
        cout << "\n===================== Results =====================" << endl;
        cout << "Mass 1: " << m1 << " kg (" << m1 * 1000 << " g)" << endl;
        cout << "Mass 2: " << m2 << " kg (" << m2 * 1000 << " g)" << endl;
        cout << "Distance: " << dist << " cm" << endl;
        cout << "G constant: " << G << " cm^3/(g*sec^2)" << endl;
        cout << "\nGravitational Force F = " << result << " dynes" << endl;
        cout << "===================================================\n" << endl;
        
        cout << "Continue? (y/n): ";
        cin >> ch;
        
    } while (ch == 'y' || ch == 'Y');
    
    cout << "\nThanks for using!" << endl;
    
    return 0;
}
