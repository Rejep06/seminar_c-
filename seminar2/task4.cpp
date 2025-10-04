#include <iostream>
#include <vector>

using namespace std;

void p(vector<int>& v, int a) {
    for (int i = 0; i < v.size(); i++) {
        v[i] += a;
    }
}

int main() {
    int a;
    cin >> a;
    vector<int> v = {2, 3, 53, 1342};
    p(v, a);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
