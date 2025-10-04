#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Time {
    int hour, minute, second;

    Time() : hour(0), minute(0), second(0) {}

    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    Time operator-(Time& other) const {
        int newSecond = second + hour * 3600 + minute * 60;
        newSecond -= other.second + other.minute * 60 + other.hour * 3600;
        if (newSecond < 0) {
            return Time();
        }
        return Time(newSecond / 3600, (newSecond % 3600) / 60, newSecond % 60);
    }

    friend ostream& operator<<(ostream& os, const Time& time) {
        os << time.hour << ':' << time.minute << ':' << time.second;
        return os;
    }
};

int main() {
    Time a(1, 25, 3), b(1, 2, 30);
    a = a - b;
    cout << a << endl;
    return 0;
}