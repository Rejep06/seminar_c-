#include <fstream>
#include <iostream>

using namespace std;

class Vector3D {
    double x, y, z;

   public:
    Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {
        cout << "Constructor with parametrs!\n";
    }

    Vector3D() : x(0), y(0), z(0) {
        cout << "Default constructor!\n";
    }

    Vector3D(const Vector3D& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        cout << "Copy constructor!\n";
    }

    ~Vector3D() {
        cout << "Destructor!\n";
    }

    Vector3D& operator=(const Vector3D& other) {
        cout << "Copy assignment operator!\n";
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
};

int main() {
    Vector3D v1;
    Vector3D v2(1, 2, 3);
    Vector3D v3(v2);
    Vector3D v4 = v1;
    v4 = v2;

    return 0;
}