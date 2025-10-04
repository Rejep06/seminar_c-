#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

vector<double> norm_vector(const vector<double>& v) {
    if (v.empty()) {
        throw invalid_argument("Вектор пустой!");
    }

    double norm = 0.0;
    for (double a : v) {
        norm += a * a;
    }
    norm = sqrt(norm);

    if (norm == 0.0) {
        throw invalid_argument("Нулевой вектор!");
    }

    vector<double> res;
    res.reserve(v.size());

    for (double value : v) {
        res.push_back(value / norm);
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<double> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    try {
        vector<double> norm_v = norm_vector(v);

        for (double a : norm_v) {
            cout << a << ' ';
        }
        cout << endl;
    } catch (const std::exception& er) {
        cout << "Error: " << er.what() << endl;
    }

    return 0;
}