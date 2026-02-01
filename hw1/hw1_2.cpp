#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double REGULAR_RATE = 36.75;
    const double OVERTIME_MULTIPLIER = 1.5;
    const double REGULAR_HOURS_LIMIT = 40.0;
    
    const double SOCIAL_SECURITY_RATE = 0.06;
    const double FEDERAL_TAX_RATE = 0.15;
    const double STATE_TAX_RATE = 0.04;
    const double LOCAL_TAX_RATE = 0.01;
    const double UNION_DUES = 20.0;
    const double HEALTH_INSURANCE = 40.0;
    const int DEPENDENTS_THRESHOLD = 2;
    
    double hoursWorked;
    int numDependents;
    
    cout << "Enter hours worked this week: ";;
    cin >> hoursWorked;
    cout << "Enter number of dependents: ";
    cin >> numDependents;
    
    double grossPay;
    if (hoursWorked <= REGULAR_HOURS_LIMIT) {
        grossPay = hoursWorked * REGULAR_RATE;
    } else {
        double regularPay = REGULAR_HOURS_LIMIT * REGULAR_RATE;
        double overtimeHours = hoursWorked - REGULAR_HOURS_LIMIT;
        double overtimePay = overtimeHours * REGULAR_RATE * OVERTIME_MULTIPLIER;
        grossPay = regularPay + overtimePay;
    }

    
    double socialSecurity = grossPay * SOCIAL_SECURITY_RATE;
    double federalTax = grossPay * FEDERAL_TAX_RATE;
    double stateTax = grossPay * STATE_TAX_RATE;
    double localTax = grossPay * LOCAL_TAX_RATE;
    double unionDues = UNION_DUES;
    
    double healthInsurance = 0.0;
    if (numDependents >= DEPENDENTS_THRESHOLD) {
        healthInsurance = HEALTH_INSURANCE;
    }
    
    double totalWithholding = socialSecurity + federalTax + stateTax + 
                             localTax + unionDues + healthInsurance;
    double netPay = grossPay - totalWithholding;
    

    cout << fixed << setprecision(2);
    cout << "\n========== PAYROLL DETAILS ==========" << endl;
    cout << "Gross Pay:                " << grossPay << endl;
    cout << "\nDeductions:" << endl;
    cout << "  Social Security (6%):   " << socialSecurity << endl;
    cout << "  Federal Income Tax (15%): " << federalTax << endl;
    cout << "  State Tax (4%):         " << stateTax << endl;
    cout << "  Local Tax (1%):         " << localTax << endl;
    cout << "  Union Dues:             " << unionDues << endl;
    cout << "  Health Insurance:       " << healthInsurance << endl;
    cout << "  Total Withholding:      " << totalWithholding << endl;
    cout << "\nNet Pay:                  " << netPay << endl;
    cout << "======================================" << endl;
    
    return 0;
}
