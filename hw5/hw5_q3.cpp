#include <iostream>
#include <string>
#include <vector>
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
    Pizza(int t, int s, int n) : type(t), size(s), numToppings(n) {}

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
        cout << "  " << getSizeName() << " " << getTypeName() << " pizza with "
             << numToppings << " topping(s)";
    }

    double computePrice() const {
        double base = 0;
        if (size == SMALL) base = 10;
        else if (size == MEDIUM) base = 14;
        else base = 17;
        return base + 2.0 * numToppings;
    }
};

class Order {
private:
    vector<Pizza> pizzas;

public:
    void addPizza(int type, int size, int toppings) {
        pizzas.push_back(Pizza(type, size, toppings));
    }

    void outputOrder() const {
        double total = 0;
        cout << "Order Summary:" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < (int)pizzas.size(); i++) {
            cout << "Pizza " << (i + 1) << ":";
            pizzas[i].outputDescription();
            double price = pizzas[i].computePrice();
            cout << " - $" << price << endl;
            total += price;
        }
        cout << "-----------------------------" << endl;
        cout << "Total: $" << total << endl;
    }
};

int main() {
    Order order1;
    order1.addPizza(DEEP_DISH, LARGE, 3);
    order1.addPizza(HAND_TOSSED, SMALL, 1);
    order1.addPizza(PAN, MEDIUM, 5);

    cout << "=== Order 1 ===" << endl;
    order1.outputOrder();
    cout << endl;

    Order order2;
    order2.addPizza(HAND_TOSSED, LARGE, 0);
    order2.addPizza(DEEP_DISH, MEDIUM, 2);

    cout << "=== Order 2 ===" << endl;
    order2.outputOrder();

    return 0;
}
