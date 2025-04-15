#include <iostream>
using namespace std;

class SmartDevice {
    public:

    SmartDevice(){}
    virtual void turnOff()=0;
    virtual void turnOn()=0;
    virtual bool getStatus()=0;

    virtual ~SmartDevice(){}

};

class LightBulb:public SmartDevice{

    private:
    bool isOn;
    int brightness;

    public:
    LightBulb(bool on,int b) {
        this->isOn=on;
        this->brightness=b;
    }
    void turnOff() override {
        isOn=false;
        cout<<"Light is Off. "<< endl;
    }

    void turnOn() override {
        isOn=true;
        cout<<"Light is On."<<endl;
    }

    bool getStatus() override {
        return isOn;
    }
};

class Thermostat:public SmartDevice{

    private:
    bool isOn;
    double temperature;

    public:
    Thermostat(bool on,double t) {
        this->isOn=on;
        this->temperature=t;
    }
    void turnOff() override {
        isOn=true;
        cout<<"Thermostat is Off. "<< endl;
    }

    void turnOn() override {
        isOn=false;
        cout<<"Thermostat is On."<<endl;
    }

    bool getStatus() override {
        return isOn;
    }
};

int main() {
    LightBulb b1(true,70);
    Thermostat t1(false, 35);

    b1.turnOff();
    cout<<"Bulb Status: "<<b1.getStatus() << endl;
    b1.turnOn();
    cout<<"Bulb Status: "<<b1.getStatus() << endl<< endl;

    t1.turnOff();
    cout<<"Thermostat Status: "<<t1.getStatus() << endl;
    t1.turnOn();
    cout<<"Thermostat Status: "<<t1.getStatus() << endl;

    
}
