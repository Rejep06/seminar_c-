#include <iostream>

using namespace std;

class Counter {
    static int cnt;

   public:

    Counter() {
        cnt++;
    }

    Counter(const Counter& other) {
        cnt++;
    }

    int getCount() {
        return cnt;
    }
};

int Counter::cnt = 0;

int main() {
    Counter c1;
    Counter c2;
    Counter c3;
    Counter c4;
    Counter c5;

    cout << c5.getCount() << '\n';
    return 0;
}