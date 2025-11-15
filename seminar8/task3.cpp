#include <iterator>
#include <ranges>

using namespace std;

template <typename T>
concept isRange = requires(T& t) {
    ranges::begin(t);
    ranges::end(t);
};

template <isRange Range, typename T, typename Pred>
size_t CountOnPrefix(Range&& range, const T& value, Pred pred) {
    size_t count = 0;

    for (const auto& x : range) {
        if (pred(x)) {
            break;
        } else if (x == value) {
            ++count;
        }
    }

    return count;
}

#include <iostream>
#include <vector>

int main() {
    vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    auto count1 = CountOnPrefix(vec, 2, [](int x) { return x >= 4; });
    cout << count1 << endl;  // 2
}