#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string a, string p, string e) 
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    string getName() const { return name; }

    virtual void displayInfo() {
        cout << endl << "Displaying information below" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string n, string i, string a, string p, string e) {
        this->name = n;
        this->id = i;
        this->address = a;
        this->phoneNumber = p;
        this->email = e;
    }
};

class Student : public Person {
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string a, string p, string e, string courses, double gpa, int year) 
        : Person(n, i, a, p, e), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
    string department;
    string coursesTaught;
    double salary;

public:
    Professor(string n, string i, string a, string p, string e, string depart, string courses, double sal) 
        : Person(n, i, a, p, e), department(depart), coursesTaught(courses), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Staff : public Person {
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string a, string p, string e, string depart, string pos, double sal) 
        : Person(n, i, a, p, e), department(depart), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Course {
    string courseID;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(string id, string name, int c, string i, string s) 
        : courseID(id), courseName(name), credits(c), instructor(i), schedule(s) {}

    void registerStudent(Student *s) {
        cout << endl << s->getName() << " registered for course: " << courseName << " (" << courseID << ")" << endl;
    }

    void calculateGrades() {
        cout << "Grades calculated for course: " << courseName << " (" << courseID << ")" << endl;
    }
};

int main() {
    Person *p[3];
    p[0] = new Student("Ahmed Raza", "24K-1010", "DHA Phase 7", "0334-5678910", "k241010@nu.edu.pk", "OOP, DLD and MVC", 3.29, 2024);
    p[1] = new Professor("Professor Shafique Rehman", "PK-0001", "Malir", "0321-4534567", "shafique.rehman@nu.edu.pk", "Computer Science", "Object Oriented Programming", 250000);
    p[2] = new Staff("Miss Madiha Rehman", "SK-0001", "Nazimabad", "0345-85868797", "madiha.rehman@nu.edu.pk", "Human Resources", "Accountant", 60000);

    for (int i = 0; i < 3; i++) {
        p[i]->displayInfo();
    }

    Course c("CS1004", "Object Oriented Programming", 3, "Miss Abeeha Sattar", "Monday, Tuesday and Thursday");
    Student s("Zain Malik", "24K-0659", "Clifton", "0312-345345", "k240659@nu.edu.pk", "Computer Science", 3.07, 2024);
    c.registerStudent(&s);
    c.calculateGrades();

    p[0]->updateInfo("Ahmed Raza", "24K-1010", "DHA Phase 7 extension", "0334-5678910", "k241010@nu.edu.pk");
    p[0]->displayInfo();

    for (int i = 0; i < 3; i++) {
        delete p[i];
    }
    return 0;
}
