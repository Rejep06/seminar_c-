#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void f(vector<int>& v) {
    sort(v.begin(), v.end());
    vector<int> ind;
    int i = 1;
    while (i < v.size()) {
        if (v[i - 1] == v[i]) {
            ind.push_back(i);
        }
        i++;
    }
    for (int j = ind.size() - 1; j >= 0; j--) {
        swap(v[ind[j]], v.back());
        v.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    f(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
