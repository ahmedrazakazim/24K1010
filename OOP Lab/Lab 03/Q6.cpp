#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
    string Company;
    string Model;
    string DpRes;
    int Ram;
    int Rom;
    int Storage;

public:
    string getCompany() {
        return Company;
    }
    string getModel() {
        return Model;
    }
    string getDpRes() {
        return DpRes;
    }
    int getRam() {
        return Ram;
    }
    int getRom() {
        return Rom;
    }
    int getStorage() {
        return Storage;
    }

    void setCompany(string comp) {
        Company = comp;
    }
    void setModel(string model) {
        Model = model;
    }
    void setDpRes(string DispRes) {
        DpRes = DispRes;
    }
    void setRam(int ram) {
        Ram = ram;
    }
    void setRom(int rom) {
        Rom = rom;
    }
    void setStorage(int storage) {
        Storage = storage;
    }

    void call() {
        string person;
        cout << "Enter the name of the person you want to call: ";
        getline(cin,person);
        cout << "Ringing... " << person << endl;
    }

    void message() {
        string message, person;
        cout << "Enter the name of the person: ";
        getline(cin,person);
        cout << "Enter the message you want to send: ";
        getline(cin, message);
        cout << "To " << person << ": \n" << message << endl;
    }

    void connectWifi() {
        int choice;
        cout << "Enter 1 to connect to Wi-Fi or 0 to disconnect: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Connected to Wi-Fi..." << endl;
        } else {
            cout << "Disconnected from Wi-Fi..." << endl;
        }
    }

    void browse() {
        string url;
        cout << "Enter the URL you want to browse: ";
        cin >> url;
        cout << "Searching " << url << "..." << endl;
    }
};

int main() {
    Smartphone phone1, phone2;

    phone1.setCompany("Apple");
    phone1.setModel("iPhone 15");
    phone1.setDpRes("2532x1170");
    phone1.setRam(6);
    phone1.setRom(128);
    phone1.setStorage(256);

    phone2.setCompany("Samsung");
    phone2.setModel("Galaxy S23");
    phone2.setDpRes("2340x1080");
    phone2.setRam(8);
    phone2.setRom(128);
    phone2.setStorage(512);

    cout << "Phone 1 - Company: " << phone1.getCompany() << ", Model: " << phone1.getModel() 
         << ", Display Resolution: " << phone1.getDpRes() << ", RAM: " << phone1.getRam() 
         << "GB, ROM: " << phone1.getRom() << "GB, Storage: " << phone1.getStorage() << "GB" << endl;

    cout << "Phone 2 - Company: " << phone2.getCompany() << ", Model: " << phone2.getModel() 
         << ", Display Resolution: " << phone2.getDpRes() << ", RAM: " << phone2.getRam() 
         << "GB, ROM: " << phone2.getRom() << "GB, Storage: " << phone2.getStorage() << "GB" << endl;

    phone1.call();
    phone2.message();

    phone1.connectWifi();
    phone2.connectWifi();

    phone1.browse();
    phone2.browse();

    return 0;
}
