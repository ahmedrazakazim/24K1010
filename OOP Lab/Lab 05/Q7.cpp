#include <iostream>
using namespace std;

class MenuItem
{
    string foodName;
    double foodPrice;

public:
    MenuItem() : foodName(""), foodPrice(0.0) {}
    MenuItem(string name, double price) : foodName(name), foodPrice(price) {}

    void setFoodName(string name) { foodName = name; }
    void setFoodPrice(double price) { foodPrice = price; }
    string getFoodName() const { return foodName; }
    double getFoodPrice() const { return foodPrice; }
};

class Menu
{
    MenuItem items[10];
    int numItems;

public:
    Menu() : numItems(0) {}

    void addItem(const MenuItem &item)
    {
        if (numItems >= 10)
        {
            cout << "Menu list is full! Cannot add more items." << endl;
            return;
        }

        items[numItems++] = item;
        cout << "Item added successfully." << endl;
    }

    void removeItem(int itemNum)
    {
        int index = itemNum - 1;
        if (index < 0 || index >= numItems)
        {
            cout << "Item number " << itemNum << " does not exist." << endl;
            return;
        }

        for (int i = index; i < numItems - 1; i++)
        {
            items[i] = items[i + 1];
        }
        numItems--;
        cout << "Item number " << itemNum << " removed successfully." << endl;
    }

    void displayMenu() const
    {
        cout << endl << "-------- Menu --------" << endl;
        for (int i = 0; i < numItems; i++)
        {
            cout << endl << "Item " << (i + 1) << ": " << endl;
            cout << "Food Name: " << items[i].getFoodName() << endl;
            cout << "Food Price: $" << items[i].getFoodPrice() << endl;
        }
    }

    MenuItem getMenuItem(int itemNum) const
    {
        int index = itemNum - 1;
        if (index < 0 || index >= numItems)
        {
            cout << "Item number " << itemNum << " does not exist." << endl;
            return MenuItem(); // returning an empty item if the item does not exist
        }

        return items[index];
    }

    int getNumberOfItems() const { return numItems; }
};

class Payment
{
    double amount;

public:
    Payment() : amount(0.0) {}
    Payment(double p) : amount(p) {}

    void displayAmount() const
    {
        cout << "Total Payment: $" << amount << endl;
    }
};

class Order
{
    MenuItem orderedItems[10];
    int numOrder;
    Payment payment;

public:
    Order() : numOrder(0) {}

    void addItem(const MenuItem &item)
    {
        if (numOrder >= 10)
        {
            cout << "Maximum order limit reached. Cannot add more items." << endl;
            return;
        }

        orderedItems[numOrder++] = item;
        cout << "Item added to order successfully." << endl;
    }

    void calculatePayment()
    {
        double total = 0;
        for (int i = 0; i < numOrder; i++)
        {
            total += orderedItems[i].getFoodPrice();
        }
        payment = Payment(total);
    }

    void displayOrder() const
    {
        cout << endl << "-------- Order Summary --------" << endl;
        for (int i = 0; i < numOrder; i++)
        {
            cout << endl << "Ordered Item " << (i + 1) << ": " << endl;
            cout << "Food Name: " << orderedItems[i].getFoodName() << endl;
            cout << "Food Price: $" << orderedItems[i].getFoodPrice() << endl;
        }
        payment.displayAmount();
    }
};

class RestaurantOrderingSystem
{
    Menu menu;

public:
    RestaurantOrderingSystem()
    {
        menu.addItem(MenuItem("Biryani", 10.99));
        menu.addItem(MenuItem("Karahi", 12.49));
        menu.addItem(MenuItem("Nihari", 11.25));
        menu.addItem(MenuItem("Salad", 4.50));
    }

    void takeOrder()
    {
        Order newOrder;
        menu.displayMenu();

        int choice;
        while (1)
        {
            cout << "Enter item number to add to your order (999 to finish): ";
            cin >> choice;

            if (choice == 999)
            {
                break;
            }

            if (choice >= 1 && choice <= menu.getNumberOfItems())
            {
                newOrder.addItem(menu.getMenuItem(choice));
            }
            else
            {
                cout << "Invalid choice. Try again." << endl;
            }
        }

        newOrder.calculatePayment();
        newOrder.displayOrder();
    }

    void showMenu() const
    {
        menu.displayMenu();
    }
};

int main()
{
    RestaurantOrderingSystem system;
    cout << "Welcome to the Restaurant Ordering System" << endl;
    system.takeOrder();
    return 0;
}
