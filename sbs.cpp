#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product(const string& n, double p) : name(n), price(p) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
};

class Cart {
private:
    vector<Product> items;

public:
    void addItem(const Product& product) {
        items.push_back(product);
    }

    void displayCart() const {
        cout << "Cart Contents:\n";
        for (const Product& item : items) {
            cout << "Name: " << item.getName() << "\n";
            cout << "Price:Rs." << fixed << setprecision(2) << item.getPrice() << "\n\n";
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const Product& item : items) {
            total += item.getPrice();
        }
        return total;
    }
};

int main() {
    vector<Product> availableProducts = {
        Product("Pomegranate", 1.0),
        Product("Banana", 0.5),
        Product("Milk", 2.0),
        // Add more products here
    };

    Cart cart;

    cout << "Available Products:\n";
    for (const Product& product : availableProducts) {
        cout << "Name: " << product.getName() << "\n";
        cout << "Price:Rs." << fixed << setprecision(2) << product.getPrice() << "\n\n";
    }

    char addMore;
    do {
        string productName;
        cout << "Enter product name to add to cart: ";
        cin >> productName;

        for (const Product& product : availableProducts) {
            if (product.getName() == productName) {
                cart.addItem(product);
                break;
            }
        }

        cout << "Add more items to cart? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    cart.displayCart();
    cout << "Total:Rs." << fixed << setprecision(2) << cart.calculateTotal() << "\n";

    return 0;
}
