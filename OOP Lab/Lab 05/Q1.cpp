#include <iostream>
#include <string>

using namespace std;

class Square {
 private:
    float sideLength;
    float area;
    static float allareas;
public:
Square () {
    sideLength = 0.0;
    area = 0.0;
    
}
Square (float sideLength) {
    this->sideLength = sideLength;
}


void setSideLength(float slength){
    sideLength = slength;
}
float getSideLength() {
    return sideLength;
}
float getArea(){
    return area;
}
static float getAllAreas() {
    return allareas;
}
void calculateArea(){
    area = getSideLength()*getSideLength();
allareas += area;
}
};
float Square::allareas=0.0;

int main() {
Square sq1(3.4);
Square sq2(4.4);
Square sq3(5.4);

sq1.calculateArea();
cout<<"Area 1: "<<sq1.getArea()<<endl;
cout<<"All Areas: "<<sq1.getAllAreas()<<endl;

sq2.calculateArea();
cout<<"Area 2: "<<sq2.getArea()<<endl;
cout<<"All Areas: "<<sq2.getAllAreas()<<endl;

sq3.calculateArea();
cout<<"Area 3: "<<sq3.getArea()<<endl;
cout<<"All Areas: "<<sq3.getAllAreas()<<endl;
}
