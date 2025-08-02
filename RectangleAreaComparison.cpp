// Program to compare area and perimeter of two rectangles using a class.

#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    // Setters
    void setLength(float l) {
        length = l;
    }

    void setWidth(float w) {
        width = w;
    }

    // Compute perimeter
    float perimeter() {
        return 2 * (length + width);
    }

    // Compute area
    float area() {
        return length * width;
    }

    // Display dimensions
    void show() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    // Compare area
    int sameArea(Rectangle r) {
        return (this->area() == r.area()) ? 1 : 0;
    }
};

int main() {
    Rectangle rect1, rect2;

    // First input set
    rect1.setLength(5);
    rect1.setWidth(2.5);

    rect2.setLength(5);
    rect2.setWidth(18.9);

    cout << "First Set of Rectangles:\n";

    cout << "Rectangle 1:\n";
    rect1.show();
    cout << "Area: " << rect1.area() << ", Perimeter: " << rect1.perimeter() << endl;

    cout << "Rectangle 2:\n";
    rect2.show();
    cout << "Area: " << rect2.area() << ", Perimeter: " << rect2.perimeter() << endl;

    if (rect1.sameArea(rect2)) {
        cout << "Both rectangles have the same area.\n";
    } else {
        cout << "Rectangles have different areas.\n";
    }

    // Second input set
    rect1.setLength(15);
    rect1.setWidth(6.3);

    cout << "\nSecond Set of Rectangles:\n";

    cout << "Rectangle 1:\n";
    rect1.show();
    cout << "Area: " << rect1.area() << ", Perimeter: " << rect1.perimeter() << endl;

    cout << "Rectangle 2:\n";
    rect2.show();
    cout << "Area: " << rect2.area() << ", Perimeter: " << rect2.perimeter() << endl;

    if (rect1.sameArea(rect2)) {
        cout << "Both rectangles have the same area.\n";
    } else {
        cout << "Rectangles have different areas.\n";
    }

    return 0;
}
