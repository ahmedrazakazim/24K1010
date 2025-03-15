/* If we do not declare our function as constant, it may allow changes to the string within the 
function. By making the function constant, we ensure that the class's data members (except mutable 
members) remain unchanged during the function's execution. */

#include <iostream>
using namespace std;

class ValidateString
{
    string str;

public:
    ValidateString() : str("") {}
    ValidateString(const string userString) : str(userString) {}

    bool isValid() const
    {
        for (int i = 0; i < str.length(); i++)
        {
            int val = static_cast<int>(str.at(i));
            if (!((val >= 65 && val <= 90) || (val >= 97 && val <= 122)))
            {
                return false;
            }
        }
        return true;
    }

    string getString() { return str; }
};

int main()
{
    ValidateString v1("Ahmed");
    cout << "String \"" << v1.getString() << "\": " << (v1.isValid() ? "Valid" : "Not Valid") << endl;

    ValidateString v2("Ahmed-1010");
    cout << "String \"" << v2.getString() << "\": " << (v2.isValid() ? "Valid" : "Not Valid") << endl;

    ValidateString v3("Hamza");
    cout << "String \"" << v3.getString() << "\": " << (v3.isValid() ? "Valid" : "Not Valid") << endl;

    ValidateString v4("Hamza#@!");
    cout << "String \"" << v4.getString() << "\": " << (v4.isValid() ? "Valid" : "Not Valid") << endl;

    return 0;
}
