#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void f(vector<T>& v, const function<bool(const T&)>& lam) {
    vector<int> ind;
    for (int i = 0; i < v.size(); i++) {
        if (!lam(v[i])) {
            ind.push_back(i);
        }
    }
    for (int j = ind.size() - 1; j >= 0; j--) {
        swap(v[ind[j]], v.back());
        v.pop_back();
    }
}

bool isPositive(int x) {
    return x > 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    f(v, function<bool(const int&)>(isPositive));

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
