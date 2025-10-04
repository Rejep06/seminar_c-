#include <iostream>
#include <vector>

using namespace std;

tuple<int, int, int> f(vector<int>& v) {
    int p = 0, o = 0, z = 0;
    for (int i = 0; i < v.size(); i++) {
        if (0 < v[i]) {
            p++;
        }
        if (0 > v[i]) {
            o++;
        }
        if (v[i] == 0) {
            z++;
        }
    }

    return make_tuple(p, o, z);
}

int main() {
    vector<int> v = {2, 3, -4, -3, 0};
    tuple<int, int, int> ans = f(v);

    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans) << endl;
    return 0;
}
