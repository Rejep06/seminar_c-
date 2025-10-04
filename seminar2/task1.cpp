#include <iostream>

using namespace std;

unsigned long long f(unsigned int x) {
    if (x == 0) {
        return 1;
    } else {
        return f(x - 1) * x;
    }
}

int main() {
    unsigned int a;
    cin >> a;

    cout << f(a) << endl;
    return 0;
}