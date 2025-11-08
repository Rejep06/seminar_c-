#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

struct Point2D {
    double x, y;

    Point2D(double x = 0, double y = 0) : x(x), y(y) {}

    Point2D operator+(const Point2D& other) const {
        return Point2D(x + other.x, y + other.y);
    }

    Point2D operator-(const Point2D& other) const {
        return Point2D(x - other.x, y - other.y);
    }

    Point2D operator*(double scalar) const {
        return Point2D(x * scalar, y * scalar);
    }

    bool operator==(const Point2D& other) const {
        return abs(x - other.x) < 1e-9 && abs(y - other.y) < 1e-9;
    }

    double distanceTo(const Point2D& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct Vector2D {
    double x, y;

    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
    Vector2D(const Point2D& from, const Point2D& to) : x(to.x - from.x), y(to.y - from.y) {}

    double length() const {
        return sqrt(x * x + y * y);
    }

    double cross(const Vector2D& other) const {
        return x * other.y - y * other.x;
    }
};

class Polygon {
   private:
    vector<Point2D> vertices;

    Point2D computeCentroid() const {
        if (vertices.empty()) return Point2D(0, 0);

        Point2D centroid(0, 0);
        for (const auto& vertex : vertices) {
            centroid = centroid + vertex;
        }
        return centroid * (1.0 / vertices.size());
    }

    double computeAngle(const Point2D& center, const Point2D& point) const {
        Vector2D vec(center, point);
        double angle = atan2(vec.y, vec.x);
        return angle < 0 ? angle + 2 * M_PI : angle;
    }

    void sortVertices() {
        if (vertices.size() < 3) return;

        Point2D center = computeCentroid();

        sort(vertices.begin(), vertices.end(),
             [&](const Point2D& a, const Point2D& b) {
                 return computeAngle(center, a) < computeAngle(center, b);
             });
    }

    bool isConvex() const {
        if (vertices.size() < 3) return true;

        int n = vertices.size();
        int sign = 0;

        for (int i = 0; i < n; ++i) {
            const Point2D& a = vertices[i];
            const Point2D& b = vertices[(i + 1) % n];
            const Point2D& c = vertices[(i + 2) % n];

            Vector2D ab(a, b);
            Vector2D bc(b, c);
            double cross_product = ab.cross(bc);

            if (abs(cross_product) > 1e-9) {
                int current_sign = (cross_product > 0) ? 1 : -1;
                if (sign == 0) {
                    sign = current_sign;
                } else if (sign != current_sign) {
                    return false;
                }
            }
        }
        return true;
    }

   public:
    Polygon() = default;

    Polygon(const vector<Point2D>& points) : vertices(points) {
        auto last = unique(vertices.begin(), vertices.end());
        vertices.erase(last, vertices.end());

        if (vertices.size() < 3) {
            throw invalid_argument("Polygon must have at least 3 distinct vertices");
        }

        sortVertices();

        if (!isConvex()) {
            throw invalid_argument("Polygon must be convex");
        }
    }

    double perimeter() const {
        if (vertices.size() < 3) return 0;

        double result = 0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            const Point2D& current = vertices[i];
            const Point2D& next = vertices[(i + 1) % vertices.size()];
            result += current.distanceTo(next);
        }
        return result;
    }

    double area() const {
        if (vertices.size() < 3) return 0;

        double result = 0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            const Point2D& current = vertices[i];
            const Point2D& next = vertices[(i + 1) % vertices.size()];
            result += current.x * next.y - current.y * next.x;
        }
        return abs(result) / 2.0;
    }

    void printInfo() const {
        cout << "Polygon with " << vertices.size() << " vertices:\n";
        for (size_t i = 0; i < vertices.size(); ++i) {
            cout << "  Vertex " << i + 1 << ": (" << vertices[i].x << ", " << vertices[i].y << ")\n";
        }
        cout << "Perimeter: " << perimeter() << "\n";
        cout << "Area: " << area() << "\n";
        cout << "Is convex: " << (isConvex() ? "Yes" : "No") << "\n";
    }
};

int main() {
    try {
        vector<Point2D> square_points = {
            Point2D(1, 1),
            Point2D(1, 0),
            Point2D(0, 0),
            Point2D(0, 1)};

        Polygon square(square_points);
        cout << "Square:\n";
        square.printInfo();
        cout << "\n";

        vector<Point2D> triangle_points = {
            Point2D(0, 0),
            Point2D(3, 0),
            Point2D(0, 4)};

        Polygon triangle(triangle_points);
        cout << "Triangle:\n";
        triangle.printInfo();
        cout << "\n";

        vector<Point2D> pentagon_points = {
            Point2D(0, 0),
            Point2D(2, 1),
            Point2D(1, 3),
            Point2D(-1, 3),
            Point2D(-2, 1)};

        Polygon pentagon(pentagon_points);
        cout << "Pentagon:\n";
        pentagon.printInfo();

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}