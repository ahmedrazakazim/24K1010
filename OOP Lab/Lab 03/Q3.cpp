#include <iostream>

using namespace std;

int countObjects = 0;

class NumberedObject
{
private:
    int id;

public:
    NumberedObject()
    {
        id = ++countObjects;
    }

    void display() const
    {
        cout << "I am object number " << id << endl;
    }
};

int main()
{
    NumberedObject firstObj, secondObj, thirdObj;

    firstObj.display();
    secondObj.display();
    thirdObj.display();

    return 0;
}
