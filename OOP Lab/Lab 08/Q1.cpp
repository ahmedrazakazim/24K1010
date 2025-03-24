#include <iostream>
#include <string>
using namespace std;

class User;

class Device {
protected:
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;

public:
    Device(string id, string type, double rating)
        : deviceID(id), deviceType(type), powerRating(rating), status(false) {}

    virtual void turnOn() {
        status = true;
        cout << deviceType << " [ID: " << deviceID << "] turned ON." << endl;
    }

    virtual void turnOff() {
        status = false;
        cout << deviceType << " [ID: " << deviceID << "] turned OFF." << endl;
    }

    virtual double calculatePowerUsage(int hours) = 0;

    string getDeviceID() const {
        return deviceID;
    }

    string getDeviceType() const {
        return deviceType;
    }

    bool getStatus() const {
        return status;
    }
};

class Light : public Device {
public:
    Light(string id, string type, double rating)
        : Device(id, type, rating) {}

    double calculatePowerUsage(int hours) override {
        return powerRating * hours;
    }
};

class Fan : public Device {
private:
    int speedFactor;

public:
    Fan(string id, string type, double rating, int speed)
        : Device(id, type, rating), speedFactor(speed) {}

    void turnOn() override {
        status = true;
        cout << deviceType << " [ID: " << deviceID << "] turned ON at Speed " << speedFactor << "." << endl;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours * speedFactor;
    }
};

class AirConditioner : public Device {
private:
    double currentTemp;
    double desiredTemp;

public:
    AirConditioner(string id, string type, double rating, double temp)
        : Device(id, type, rating), desiredTemp(temp), currentTemp(30) {}

    void turnOn() override {
        status = true;
        cout << deviceType << " [ID: " << deviceID << "] turned ON. Cooling to " << desiredTemp << "°C." << endl;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours * (1 - (currentTemp - desiredTemp) / 100);
    }
};

class SecuritySystem : public Device {
private:
    bool securityStatus;

public:
    SecuritySystem(string id, string type, double rating)
        : Device(id, type, rating), securityStatus(false) {}

    void turnOn() override {
        status = true;
        securityStatus = true;
        cout << deviceType << " [ID: " << deviceID << "] activated." << endl;
    }

    void turnOff() override {
        if (securityStatus) {
            cout << "Authorization required to turn OFF the security system." << endl;
        } else {
            status = false;
        }
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours + (securityStatus ? 100 : 0);
    }

    friend class MaintenanceTool;
    friend void accessSecurityLogs(SecuritySystem& secSys, User& user);
};

class User {
private:
    string userID;
    string userRole;
    int accessLevel;

public:
    User(string id, string role, int access)
        : userID(id), userRole(role), accessLevel(access) {}

    void viewAccessibleDevices(Device* devices[], int deviceCount) {
        cout << "User: " << userID << " - Accessible Devices:" << endl;
        for (int i = 0; i < deviceCount; i++) {
            if (devices[i]->getDeviceType() != "Security System" || accessLevel == 2) {
                cout << "- " << devices[i]->getDeviceType() << " [ID: " << devices[i]->getDeviceID() << "]" << endl;
            }
        }
    }

    int getAccessLevel() const {
        return accessLevel;
    }
};

class MaintenanceTool {
public:
    void resetSecurityAlerts(SecuritySystem& secSys) {
        secSys.securityStatus = false;
        cout << "Security alerts reset for " << secSys.getDeviceID() << "." << endl;
    }
};

void accessSecurityLogs(SecuritySystem& secSys, User& user) {
    if (user.getAccessLevel() == 2) {
        cout << "User: " << user.getAccessLevel() << " - Security Logs Accessed:" << endl;
        cout << "- Intrusion Detected at 3:00 AM" << endl;
        cout << "- System Reset Required" << endl;
    } else {
        cout << "Access denied. Only maintenance staff can view security logs." << endl;
    }
}

int main() {
    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);

    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AirConditioner ac1("AC001", "Split AC", 1500, 25);
    SecuritySystem secSys1("S001", "Home Alarm", 100);

    Device* devices[] = { &light1, &fan1, &ac1, &secSys1 };
    int deviceCount = 4;

    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();

    cout << "Power Consumption:" << endl;
    cout << "LED Light: " << light1.calculatePowerUsage(5) << " Watts" << endl;
    cout << "Ceiling Fan: " << fan1.calculatePowerUsage(3) << " Watts" << endl;
    cout << "Split AC: " << ac1.calculatePowerUsage(6) << " Watts" << endl;
    cout << "Security System: " << secSys1.calculatePowerUsage(24) << " Watts (Includes security checks)" << endl;

    user1.viewAccessibleDevices(devices, deviceCount);
    accessSecurityLogs(secSys1, user2);

    return 0;
}
