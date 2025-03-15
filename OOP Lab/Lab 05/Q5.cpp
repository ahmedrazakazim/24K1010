#include <iostream>
using namespace std;

class Engine
{
public:
    Engine()
    {
        cout << "Engine has been created." << endl;
    }

    ~Engine()
    {
        cout << "Engine has been destroyed." << endl;
    }
};

class Wheels
{
public:
    Wheels()
    {
        cout << "Wheels have been created." << endl;
    }

    ~Wheels()
    {
        cout << "Wheels have been destroyed." << endl;
    }
};

class Headlights
{
public:
    Headlights()
    {
        cout << "Headlights have been created." << endl;
    }

    ~Headlights()
    {
        cout << "Headlights have been destroyed." << endl;
    }
};

class Steering
{
public:
    Steering()
    {
        cout << "Steering has been created." << endl;
    }

    ~Steering()
    {
        cout << "Steering has been destroyed." << endl;
    }
};

class Car
{
    Engine *engine;
    Wheels *wheels;
    Steering steering;
    Headlights headlights;

public:
    Car() : engine(nullptr), wheels(nullptr) {}
    Car(Engine *e, Wheels *w) : engine(e), wheels(w)
    {
        cout << "Car has been created." << endl;
    }

    void setEngine(Engine *e) { engine = e; }

    void setWheels(Wheels *w) { wheels = w; }

    ~Car()
    {
        cout << "Car has been destroyed." << endl;
    }
};

int main()
{
    Engine toyotaEngine;
    Wheels goodyear;
    Car hondaCivic(&toyotaEngine, &goodyear);
    return 0;
}
