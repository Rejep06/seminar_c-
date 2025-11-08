#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Shape {
   private:
    string name;
    string color;
    double x, y;  // coordinates of centre
   public:
    Shape(const string& name, const string& color, double x, double y) : name(name), color(color), x(x), y(y) {}

    virtual ~Shape() = default;

    virtual double area() const = 0;

    virtual void displayInfo() const {
        cout << "Figure: " << name << ", color: " << color << ", centre: (" << x << ", " << y << ")";
    }

    string getName() const { return name; }
    string getColor() const { return color; }
    double getX() const { return x; }
    double getY() const { return y; }
};

class Circle : public Shape {
   private:
    double radius;

   public:
    Circle(const string& name, const string& color, double x, double y, double radius)
        : Shape(name, color, x, y), radius(radius) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << ", radius: " << radius << ", area: " << area() << endl;
    }

    double getRadius() const { return radius; }
    void setRadius(double newRadius) { radius = newRadius; }

    double circumference() const {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
   private:
    double width, height;

   public:
    Rectangle(const string& name, const string& color, double x, double y,
              double width, double height, double rotation = 0)
        : Shape(name, color, x, y), width(width), height(height) {}

    double area() const override {
        return width * height;
    }

    double getWidth() const { return width; }
    double getHeight() const { return height; }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << ", width: " << width << ", height: " << height
             << ", area: " << area() << endl;
    }

    void setWidth(double newWidth) {
        width = newWidth;
    }
    void setHeight(double newHeight) {
        height = newHeight;
    }

    double diagonal() const {
        return sqrt(width * width + height * height);
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>("circle1", "red", 0, 0, 5.0));
    shapes.push_back(make_unique<Rectangle>("rectangle1", "black", 2, 3, 4.0, 6.0));
    shapes.push_back(make_unique<Circle>("circle2", "yellow", 5, -2, 3.0));
    shapes.push_back(make_unique<Rectangle>("rectangle2", "blue", -3, -3, 5.0, 3.0));

    for (const auto& shape : shapes) {
        shape->displayInfo();
    }

    if (auto circle = dynamic_cast<Circle*>(shapes[0].get())) {
        cout << "Длина окружности " << circle->getName() << ": " << circle->circumference() << endl;
    }

    if (auto rect = dynamic_cast<Rectangle*>(shapes[1].get())) {
        cout << "Диагональ " << rect->getName() << ": " << rect->diagonal() << endl;
    }
    return 0;
}