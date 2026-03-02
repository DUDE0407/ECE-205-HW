#include <iostream>
using namespace std;

// input function
void getWeight(int &pounds, int &ounces) {
    cout << "Enter weight in pounds: ";
    cin >> pounds;
    cout << "Enter ounces: ";
    cin >> ounces;
}

// conversion function (void with pass-by-reference)
void convertWeight(int pounds, int ounces, int &kg, int &grams) {
    // convert everything to ounces first
    int totalOz = pounds * 16 + ounces;
    
    // convert to grams (1 lb = 453.592g, so 1 oz = 28.3495g)
    double totalGrams = totalOz / 2.2046 * 1000.0 / 16.0;
    
    // separate into kg and g
    kg = (int)(totalGrams / 1000.0);
    grams = (int)(totalGrams) % 1000;
}

// output function
void displayWeight(int pounds, int ounces, int kg, int grams) {
    cout << pounds << "lb " << ounces << "oz = ";
    cout << kg << "kg " << grams << "g" << endl;
}

int main() {
    char choice;
    
    do {
        int lb, oz, kilos, g;
        
        cout << "\nWeight Converter (Imperial to Metric)" << endl;
        cout << "======================================" << endl;
        
        getWeight(lb, oz);
        
        // validate input
        if (lb < 0 || oz < 0 || oz >= 16) {
            cout << "Invalid input! Ounces must be 0-15." << endl;
            continue;
        }
        
        convertWeight(lb, oz, kilos, g);
        displayWeight(lb, oz, kilos, g);
        
        cout << "\nConvert another weight? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Thank you!" << endl;
    
    return 0;
}
