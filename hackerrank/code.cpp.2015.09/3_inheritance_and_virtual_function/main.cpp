// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/virtual-function
#include <iostream>

using namespace std;

class Rectangle {
public:
    void Display() { // to display the dimensions of rectangle
        cout << width << " " << height << endl;
    }

protected:
    int width, height;
};

class RectangleArea : public Rectangle {
public:
    void Input() { // to read the width and height of a rectangle
        cin >> width >> height;
    }
    virtual void Display() { // to display the area of rectangle
        cout << width * height << endl;
    }
};

int main() {
    RectangleArea r_area;
    r_area.Input();
    Rectangle *r;
    r=&r_area;
    r->Display();
    r_area.Display();
    return 0;
}
