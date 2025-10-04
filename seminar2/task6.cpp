#include <iostream>
#include <vector>

using namespace std;

template <typename T>
pair<T, T> f(const vector<T>& v) {
    pair<T, T> a = {v[0], v[0]};
    for (int i = 1; i < v.size(); i++) {
        if (a.first < v[i]) {
            a.first = v[i];
        }
        if (a.second > v[i]) {
            a.second = v[i];
        }
    }
    return a;
}

int main() {
    vector<double> v = {2, 3, 4, 53, 1342};
    pair<double, double> ans = f(v);

    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}
