#include <iostream>
using namespace std;

class Vehicle {
protected:
string model;
double rate;

public:
Vehicle(string m, double r) {
    this->model=m;
    this->rate=r;

}
virtual double getDailyRate()=0;
virtual void displayDetails()=0;


};
class Car : public Vehicle {

    public:
    Car(string m, double r) : Vehicle(m,r) {}
    
    double getDailyRate() override {
        return rate;
    }
    void displayDetails() override {
        cout<<"### Car Details ###"<< endl;
        cout<<"Model: "<< model <<endl;
        cout<<"Daily Rate: "<< rate <<endl;

    }
};
class Bike : public Vehicle {

    public:
    Bike(string m, double r) : Vehicle(m,r) {};
    
    double getDailyRate() override {
        return rate;
    }
    void displayDetails() override {
        cout<<"### Car Details ###"<< endl;
        cout<<"Model: "<< model <<endl;
        cout<<"Daily Rate: "<< rate <<endl;

    }
};

int main() {
    Car c1("Mustang Shelby GT 500", 1300000);
    Bike b1("Kawasaki Ninja",650000);
    c1.displayDetails();
    b1.displayDetails();

    cout<<"Car Daily Rate: "<< c1.getDailyRate()<<endl;
    cout<<"Bike Daily Rate: "<< b1.getDailyRate()<<endl;
}
