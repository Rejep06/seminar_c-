#include <iostream>
#include <vector>

using namespace std;

void p(vector<double>& v) {
    for (int i = 0; i < v.size() / 2; i++) {
        swap(v[i], v[v.size() - i - 1]);
    }
}

int main() {
    vector<double> v = {2, 3, 4, 53, 1342};
    p(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
