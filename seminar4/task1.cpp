#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<int> st;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(1);
        if (s[i] == '[') st.push(2);
        if (s[i] == '{') st.push(3);

        if (s[i] == ')') {
            if (st.top() == 1) {
                st.pop();
            } else {
                cout << "NO\n";
                return 0;
            }
        }

        if (s[i] == ']') {
            if (st.top() == 2) {
                st.pop();
            } else {
                cout << "NO\n";
                return 0;
            }
        }

        if (s[i] == '}') {
            if (st.top() == 3) {
                st.pop();
            } else {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}