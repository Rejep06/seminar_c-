#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

double sqr(double x) {
    return x * x;
}

struct Triangle {
    double leg1, leg2;
    Triangle(double l1, double l2) : leg1(l1), leg2(l2) {}

    auto operator<=>(const Triangle& other) const {
        return sqrt(sqr(leg1) + sqr(leg2)) <=> sqrt(sqr(other.leg1) + sqr(other.leg2));
    }

    friend ostream& operator<<(ostream& os, const Triangle& triangle) {
        os << triangle.leg1 << ' ' << triangle.leg2;
        return os;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Triangle> v;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }

    sort(v.begin(), v.end());
    cout << endl;

    for (auto tr : v) {
        cout << tr << '\n';
    }

    return 0;
}