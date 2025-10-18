#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class GreaterThan {
    T value;

   public:
    GreaterThan(const T& value_) : value(value_) {}

    // bool operator()(const T& other) {
    //     return other > value;
    // }
    bool operator()(const T& other, const T& other2) {
        return other > value;
    }
};

int main() {
    vector<int> v{1, 2, 9, 4, 7, 10};

    GreaterThan<int> g_5(5);

    cout << count_if(v.begin(), v.end(), g_5) << '\n';

    return 0;
}