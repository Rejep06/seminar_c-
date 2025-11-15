#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

template <ranges::input_range Range, typename Pred>
auto FilterSortedUnique(Range&& range, Pred pred) {
    using ValueType = ranges::range_value_t<Range>;

    auto filtered = views::filter(range, pred);

    vector<ValueType> result;

    ranges::copy(filtered, std::back_inserter(result));

    ranges::sort(result);

    auto [first, last] = std::ranges::unique(result);
    result.erase(first, last);

    return result;
}

int main() {
    vector<int> numbers = {5, 2, 8, 2, 3, 5, 1, 8, 9, 4, 2, 7};

    auto result1 = FilterSortedUnique(numbers, [](int x) {
        return x % 2 == 0;
    });
    for (int x : result1) {
        cout << x << " ";
    }
    cout << endl;  // 2 4 8
}