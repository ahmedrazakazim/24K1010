#include <iostream>
using namespace std;

class Product {
protected:
    string productID;
    double price;

public:
    Product(string id, double p)
        : productID(id), price(p) {}

    virtual ~Product() {}

    virtual double calculatePrice() const = 0;

    virtual void applyDiscount(double percentage) {
        price *= (1 - percentage / 100);
    }

    virtual Product* clone() const = 0;

    string getProductID() const { return productID; }
    double getPrice() const { return price; }
};

class Electronics : public Product {
public:
    Electronics(string id, double p) : Product(id, p) {}

    double calculatePrice() const override {
        return price * 1.15; // 15% tax
    }

    void applyDiscount(double percentage) override {
        price *= (1 - percentage / 100);
    }

    Product* clone() const override {
        return new Electronics(*this);
    }
};

class Clothing : public Product {
public:
    Clothing(string id, double p) : Product(id, p) {}

    double calculatePrice() const override {
        return price * 1.05; // 5% tax
    }

    void applyDiscount(double percentage) override {
        price *= (1 - percentage / 100);
    }

    Product* clone() const override {
        return new Clothing(*this);
    }
};

class ShoppingCart {
private:
    Product* items[100];
    int itemCount;

public:
    ShoppingCart() : itemCount(0) {}

    ShoppingCart(const ShoppingCart& other) : itemCount(other.itemCount) {
        for (int i = 0; i < itemCount; ++i) {
            items[i] = other.items[i]->clone();
        }
    }

    ~ShoppingCart() {
        for (int i = 0; i < itemCount; ++i) {
            delete items[i];
        }
    }

    void addItem(Product* p) {
        if (itemCount < 100) {
            items[itemCount++] = p->clone();
        }
    }

    void removeItem(int index) {
        if (index < 0 || index >= itemCount) return;
        delete items[index]; // Free memory
        for (int i = index; i < itemCount - 1; ++i) {
            items[i] = items[i + 1];
        }
        itemCount--;
    }

    double totalPrice() const {
        double total = 0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->calculatePrice();
        }
        return total;
    }

    ShoppingCart operator+(const ShoppingCart& other) const {
        ShoppingCart newCart = *this;
        for (int i = 0; i < other.itemCount && newCart.itemCount < 100; ++i) {
            newCart.addItem(other.items[i]);
        }
        return newCart;
    }

    ShoppingCart operator-(int index) const {
        ShoppingCart newCart = *this;
        newCart.removeItem(index);
        return newCart;
    }

    ShoppingCart operator*(double discount) const {
        ShoppingCart newCart;
        for (int i = 0; i < itemCount; ++i) {
            Product* discountedProduct = items[i]->clone();
            discountedProduct->applyDiscount(discount * 100);
            newCart.addItem(discountedProduct);
            delete discountedProduct;
        }
        return newCart;
    }

    double operator/(int users) const {
        return (users > 0) ? totalPrice() / users : 0;
    }

    void displayCart() const {
        for (int i = 0; i < itemCount; ++i) {
            cout << "Item " << i + 1 << ": " << items[i]->getProductID() 
                 << " - Price: " << items[i]->calculatePrice() << endl;
        }
        cout << "Total Price: " << totalPrice() << endl;
    }
};

int main() {
    ShoppingCart cart1, cart2;

    cart1.addItem(new Electronics("E01", 1000));
    cart1.addItem(new Clothing("C01", 500));

    cart2.addItem(new Electronics("E02", 800));
    cart2.addItem(new Clothing("C02", 400));

    cout << "Cart 1 Details:\n";
    cart1.displayCart();

    cout << "\nCart 2 Details:\n";
    cart2.displayCart();

    ShoppingCart mergedCart = cart1 + cart2;
    cout << "\nMerged Cart:\n";
    mergedCart.displayCart();

    ShoppingCart removedCart = mergedCart - 1;
    cout << "\nAfter Removing Item from Merged Cart:\n";
    removedCart.displayCart();

    ShoppingCart discountedCart = removedCart * 0.1;
    cout << "\nAfter Applying 10% Discount:\n";
    discountedCart.displayCart();

    double splitAmount = discountedCart / 3;
    cout << "\nEach Person Pays: " << splitAmount << endl;

    return 0;
}
