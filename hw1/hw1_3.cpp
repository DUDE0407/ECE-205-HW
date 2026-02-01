#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    const double INITIAL_DEBT = 1000.0;
    const double MONTHLY_INTEREST_RATE = 0.015;
    const double MONTHLY_PAYMENT = 50.0;
    
    double balance = INITIAL_DEBT;
    double totalInterest = 0.0;
    double totalPaid = 0.0;
    int month = 0;
    
    cout << fixed << setprecision(2);
    cout << "Loan Repayment Schedule" << endl;
    cout << "Initial Debt: $" << INITIAL_DEBT << endl;
    cout << "Annual Interest Rate: 18% (Monthly Rate: 1.5%)" << endl;
    cout << "Monthly Payment: $" << MONTHLY_PAYMENT << endl;
    cout << "\n" << right;
    cout << "Month #  Interest  Principal    Balance Total Interest   Total Paid" << endl;
    cout << string(75, '-') << endl;
    
    while (balance > 0) {
        month++;
        
        double interest = balance * MONTHLY_INTEREST_RATE;
        
        double payment;
        if (balance + interest <= MONTHLY_PAYMENT) {
            payment = balance + interest;
        } else {
            payment = MONTHLY_PAYMENT;
        }
        
        double principal = payment - interest;
        
        balance -= principal;

        
        totalInterest += interest;
        totalPaid += payment;
        
        ostringstream oss1, oss2, oss3, oss4, oss5;
        oss1 << fixed << setprecision(2) << "$" << interest;
        oss2 << fixed << setprecision(2) << "$" << principal;
        oss3 << fixed << setprecision(2) << "$" << balance;
        oss4 << fixed << setprecision(2) << "$" << totalInterest;
        oss5 << fixed << setprecision(2) << "$" << totalPaid;
        
        cout << setw(7) << month
             << setw(10) << oss1.str()
             << setw(11) << oss2.str()
             << setw(12) << oss3.str()
             << setw(15) << oss4.str()
             << setw(13) << oss5.str() << endl;     
    }
    
    cout << string(75, '-') << endl;
    cout << "\nRepayment Summary:" << endl;
    cout << "Total Months:    " << month << " months" << endl;
    cout << "Total Interest:  $" << totalInterest << endl;
    cout << "Total Paid:      $" << totalPaid << endl;
    
    return 0;
}
