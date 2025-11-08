#include <iostream>

using namespace std;

class Counter {
    static int cnt;
    static int cntCur;

   public:
    Counter() {
        cnt++;
        cntCur++;
    }

    Counter(const Counter& other) {
        cnt++;
        cntCur++;
    }

    ~Counter() {
        cntCur--;
    }

    static int getCount() {
        return cnt;
    }

    static int getCurrentCount() {
        return cntCur;
    }
};

int Counter::cnt = 0;
int Counter::cntCur = 0;

int main() {
    Counter c1;
    Counter c2;
    Counter c3;
    {
        Counter c4;
        Counter c5;
    }
    cout << Counter::getCurrentCount() << '\n';
    cout << Counter::getCount() << '\n';
    return 0;
}