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

    ~Counter() {
        cnt--;
    }

    int getCount() {
        return cnt;
    }

    static int getCurrentCount() {
        return cnt;
    }
};

int Counter::cnt = 0;

int main() {
    Counter c1;
    Counter c2;
    Counter c3;
    {
        Counter c4;
        Counter c5;
    }
    cout << Counter::getCurrentCount() << '\n';
    return 0;
}