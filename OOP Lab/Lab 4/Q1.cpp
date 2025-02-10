#include <iostream>

using namespace std;

class Student {
private:
    int studentID;
    string name;
    int age;
    char grade;
public:
Student () {
grade = 'N';
}
Student (int ID, string Name, int Age, char Grade) {
    studentID = ID;
    name = Name;
    age = Age;
    grade = Grade;
}
void promoteStudent() {
    grade--;
        if (grade < 'A') 
        grade = 'A';

        if (grade == 'E')
        grade = 'D';
}

bool isEligibleForScholarship() {
    
        return grade =='A' ;
        
}
void displayDetails() {
    cout <<"Student ID: "<< studentID << endl;
    cout <<"Name: "<< name << endl;
    cout <<"Age: "<< age << endl;
    cout <<"Grade: "<< grade << endl;
}
};

int main() {
    Student std1(202, "Faran", 19, 'C'),std2;
    Student std3 = Student(1010, "Ahmed", 20, 'A');
    std1.displayDetails();
    std3.displayDetails();
    std1.promoteStudent();
    std1.displayDetails();
    cout << "Is student eligible for scholarship: "<< std1.isEligibleForScholarship()<<endl;
    cout << "Is student eligible for scholarship: "<< std3.isEligibleForScholarship()<<endl;

}
