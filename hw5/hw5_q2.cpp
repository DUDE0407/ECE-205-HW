#include <iostream>
#include <string>
using namespace std;

const int DEEP_DISH = 0;
const int HAND_TOSSED = 1;
const int PAN = 2;

const int SMALL = 0;
const int MEDIUM = 1;
const int LARGE = 2;

class Pizza {
private:
    int type;
    int size;
    int numToppings;

public:
    Pizza() : type(HAND_TOSSED), size(SMALL), numToppings(0) {}

    void setType(int t) { type = t; }
    void setSize(int s) { size = s; }
    void setNumToppings(int n) { numToppings = n; }

    int getType() const { return type; }
    int getSize() const { return size; }
    int getNumToppings() const { return numToppings; }

    string getTypeName() const {
        if (type == DEEP_DISH) return "Deep Dish";
        if (type == HAND_TOSSED) return "Hand Tossed";
        return "Pan";
    }

    string getSizeName() const {
        if (size == SMALL) return "Small";
        if (size == MEDIUM) return "Medium";
        return "Large";
    }

    void outputDescription() const {
        cout << getSizeName() << " " << getTypeName() << " pizza with "
             << numToppings << " topping(s)" << endl;
    }

    double computePrice() const {
        double base = 0;
        if (size == SMALL) base = 10;
        else if (size == MEDIUM) base = 14;
        else base = 17;
        return base + 2.0 * numToppings;
    }
};

int main() {
    Pizza p1;
    p1.setType(DEEP_DISH);
    p1.setSize(LARGE);
    p1.setNumToppings(3);
    p1.outputDescription();
    cout << "Price: $" << p1.computePrice() << endl;
    cout << endl;

    Pizza p2;
    p2.setType(HAND_TOSSED);
    p2.setSize(SMALL);
    p2.setNumToppings(1);
    p2.outputDescription();
    cout << "Price: $" << p2.computePrice() << endl;
    cout << endl;

    Pizza p3;
    p3.setType(PAN);
    p3.setSize(MEDIUM);
    p3.setNumToppings(5);
    p3.outputDescription();
    cout << "Price: $" << p3.computePrice() << endl;

    return 0;
}
