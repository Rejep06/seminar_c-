#include <iostream>
#include <iterator>
#include <list>
#include <stack>

using namespace std;

template <typename ForwardIt>
void reverse_print(ForwardIt begin, ForwardIt end) {
    stack<iter_value_t<ForwardIt>> st;

    for (auto it = begin; it != end; ++it) {
        st.push(*it);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    list<int> lt = {7, 5, 16, 8};
    reverse_print(lt.begin(), lt.end());
    cout << endl;
    return 0;
}