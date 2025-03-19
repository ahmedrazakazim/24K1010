#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    int posX, posY;
    string col;
    int borderThick;

public:
    Shape(int pX, int pY, string c, int bT = 1) 
        : posX(pX), posY(pY), col(c), borderThick(bT) {}
    
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    int rad;
    int centerX, centerY;

public:
    Circle(int r, int cX, int cY, int pX, int pY, string c, int bT = 1) 
        : rad(r), centerX(cX), centerY(cY), Shape(pX, pY, c, bT) {}

    void draw() override {
        cout << "Drawing a circle at (" << posX << ", " << posY << ") at center: (" << centerX << ", " << centerY << ") with radius: " << rad << ", color: " << col << ", and border thickness: " << borderThick << endl;
    }

    double calculateArea() override {
        return (3.14159 * rad * rad);
    }

    double calculatePerimeter() override {
        return (2 * 3.14159 * rad);
    }
};

class Rectangle : public Shape {
    int w, h;

public:
    Rectangle(int width, int height, int pX, int pY, string c, int bT = 1) 
        : w(width), h(height), Shape(pX, pY, c, bT) {}

    void draw() override {
        cout << "Drawing a rectangle at (" << posX << ", " << posY << ") with width: " << w << ", height: " << h << ", color: " << col << ", and border thickness: " << borderThick << endl;
    }

    double calculateArea() override {
        return (h * w);
    }

    double calculatePerimeter() override {
        return (2 * (h + w));
    }
};

class Triangle : public Shape {
    int s1, s2, s3;

public:
    Triangle(int side1, int side2, int side3, int pX, int pY, string c, int bT = 1) 
        : s1(side1), s2(side2), s3(side3), Shape(pX, pY, c, bT) {}

    void draw() override {
        cout << "Drawing a triangle at (" << posX << ", " << posY << ") with sides: " << s1 << ", " << s2 << ", " << s3 << ", color: " << col << ", and border thickness: " << borderThick << endl;
    }

    double calculateArea() override {
        double s = (s1 + s2 + s3) / 2.0;
        return sqrt(s * (s - s1) * (s - s2) * (s - s3));
    }

    double calculatePerimeter() override {
        return (s1 + s2 + s3);
    }
};

class Polygon : public Shape {
    int sideLen;
    int numSides;

public:
    Polygon(int sideLength, int num, int pX, int pY, string c, int bT = 1) 
        : sideLen(sideLength), numSides(num), Shape(pX, pY, c, bT) {}

    void draw() override {
        cout << "Drawing a regular polygon at (" << posX << ", " << posY << ") with " << numSides << " sides of length " << sideLen << ", color: " << col << ", and border thickness: " << borderThick << endl;
    }

    double calculatePerimeter() override {
        return (numSides * sideLen);
    }

    double calculateArea() override {
        if (numSides < 3) {
            cout << "A polygon must have at least 3 sides." << endl;
            return 0.0;
        }
        return (numSides * sideLen * sideLen) / (4.0 * tan(3.14159 / numSides));
    }
};

int main() {
    Circle c(5, 10, 10, 3, 3, "red", 2);
    c.draw();
    cout << "Circle Area: " << c.calculateArea() << endl;
    cout << "Circle Perimeter: " << c.calculatePerimeter() << endl << endl;

    Rectangle r(10, 5, 2, 2, "blue", 3);
    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << endl << endl;

    Triangle t(3, 4, 5, 1, 1, "green", 1);
    t.draw();
    cout << "Triangle Area: " << t.calculateArea() << endl;
    cout << "Triangle Perimeter: " << t.calculatePerimeter() << endl << endl;

    Polygon hexagon(5, 6, 0, 0, "purple", 2);
    hexagon.draw();
    cout << "Hexagon Area: " << hexagon.calculateArea() << endl;
    cout << "Hexagon Perimeter: " << hexagon.calculatePerimeter() << endl << endl;

    return 0;
}
