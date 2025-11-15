#include <concepts>
#include <type_traits>
#include <vector>

using namespace std;

template <typename T>
concept Arithmetic = is_arithmetic_v<T>;

template <typename T>
concept HasPlus = requires(T a, T b) {
    { a + b } -> convertible_to<T>;
};

template <typename T>
    requires Arithmetic<T>
T Sum(const vector<T>& v) {
    T res = T();
    for (const auto& el : v) {
        res += el;
    }
    return res;
}

template <typename T>
    requires HasPlus<T> && (!Arithmetic<T>)
T Sum(const vector<T>& v) {
    if (v.empty()) {
        return T();
    }

    T result = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        result = result + v[i];
    }
    return result;
}

#include <iostream>
#include <string>

int main() {
    vector<int> int_vec = {1, 2, 3, 4, 5};

    cout << Sum(int_vec) << endl;  // 15

    vector<string> str_vec = {"Hello", " ", "World"};

    cout << Sum(str_vec) << endl;  // "Hello World"

    return 0;
}