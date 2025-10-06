#include <algorithm>
#include <concepts>
#include <deque>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

template <typename T>
concept Integral = std::integral<T>;

template <input_iterator Iter>
    requires Integral<iter_value_t<Iter>>
iterator_traits<Iter>::difference_type
count_even(Iter first, Iter last) {
    return count_if(first, last, [](auto x) { return x % 2 == 0; });
}

template <input_iterator InputIter, output_iterator<iter_value_t<InputIter>> OutputIter>
    requires Integral<iter_value_t<InputIter>>
OutputIter copy_even(InputIter first, InputIter last, OutputIter iter) {
    return copy_if(first, last, iter, [](auto x) { return x % 2 == 0; });
}

template <forward_iterator ForwardIter>
    requires Integral<iter_value_t<ForwardIter>>
ForwardIter remove_even(ForwardIter first, ForwardIter last) {
    return remove_if(first, last, [](auto x) { return x % 2 == 0; });
}

int main() {
    vector<int> v{1, 2, 3, 4, 5};

    auto even_count = count_even(v.begin(), v.end());
    cout << count_even(v.begin(), v.end()) << '\n';
    deque<int> d;
    copy_even(v.begin(), v.end(), back_inserter(d));
    cout << *d.begin() << '\n';
    remove_even(v.begin(), v.end());
    cout << count_even(v.begin(), v.end()) << '\n';
}