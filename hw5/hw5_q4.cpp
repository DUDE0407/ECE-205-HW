#include <iostream>
using namespace std;

class PrimeNumber {
private:
    int prime;

    static bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    static int nextPrime(int n) {
        int candidate = n + 1;
        while (!isPrime(candidate)) candidate++;
        return candidate;
    }

    static int prevPrime(int n) {
        if (n <= 2) return 1;
        int candidate = n - 1;
        while (candidate > 1 && !isPrime(candidate)) candidate--;
        if (candidate <= 1) return 1;
        return candidate;
    }

public:
    PrimeNumber() : prime(1) {}
    PrimeNumber(int p) : prime(p) {}

    int getPrime() const { return prime; }

    PrimeNumber operator++() {
        prime = nextPrime(prime);
        return *this;
    }

    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;
        prime = nextPrime(prime);
        return temp;
    }

    PrimeNumber operator--() {
        prime = prevPrime(prime);
        return *this;
    }

    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        prime = prevPrime(prime);
        return temp;
    }
};

int main() {
    PrimeNumber pn1;
    cout << "Default prime: " << pn1.getPrime() << endl;

    PrimeNumber pn2(13);
    cout << "Initial prime: " << pn2.getPrime() << endl;

    ++pn2;
    cout << "After prefix ++: " << pn2.getPrime() << endl;

    pn2++;
    cout << "After postfix ++: " << pn2.getPrime() << endl;

    --pn2;
    cout << "After prefix --: " << pn2.getPrime() << endl;

    pn2--;
    cout << "After postfix --: " << pn2.getPrime() << endl;

    cout << endl;
    cout << "Traversing primes from 2:" << endl;
    PrimeNumber pn3(2);
    for (int i = 0; i < 10; i++) {
        cout << pn3.getPrime() << " ";
        pn3++;
    }
    cout << endl;

    return 0;
}
