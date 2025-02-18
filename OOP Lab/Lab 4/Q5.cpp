#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeID;
    string name;
    string department;
    double salary;

public:
    Employee() : salary(0.0) {}

    Employee(int id, string empName, string dept, double empSalary) {
        this->employeeID = id;
        this->name = empName;
        this->department = dept;
        this->salary = empSalary;
    }

    void giveBonus(double amount) {
        salary += amount;
        cout << "Bonus of $" << amount << " added to " << name << "'s salary." << endl;
    }

    bool isManager() {
        return (this->department == "Management");
    }

    void displayDetails() {
        cout << "Employee ID: " << this->employeeID << endl;
        cout << "Name: " << this->name << endl;
        cout << "Department: " << this->department << endl;
        cout << "Salary: $" << this->salary << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    Employee emp1(101, "Alice", "Management", 75000);
    Employee emp2(102, "Bob", "HR", 50000);
    Employee emp3(103, "Charlie", "Engineering", 60000);

    emp1.displayDetails();
    emp2.displayDetails();
    emp3.displayDetails();

    emp1.giveBonus(5000);

    if (emp1.isManager()) {
        cout << emp1.name << " is a manager." << endl;
    } else {
        cout << emp1.name << " is not a manager." << endl;
    }

    emp1.displayDetails();

    return 0;
}
