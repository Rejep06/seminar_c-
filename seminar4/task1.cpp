#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<int> st;
    map<char, int> mp = {{'()', 1}, };
    mp['('] = 1;
    mp[')'] = -1;
    mp['['] = 2;
    mp[']'] = -2;
    mp['{'] = 3;
    mp['}'] = -3;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (mp[s[i]] > 0)
            st.push(mp[s[i]]);
        else {
            if (st.top() + mp[s[i]]) {
                cout << "NO\n";
                return 0;
            }
            st.pop();
        }
        // if (s[i] == '(') st.push(1);
        // if (s[i] == '[') st.push(2);
        // if (s[i] == '{') st.push(3);

        // if (s[i] == ')') {
        //     if (st.top() == 1) {
        //         st.pop();
        //     } else {
        //         cout << "NO\n";
        //         return 0;
        //     }
        // }

        // if (s[i] == ']') {
        //     if (st.top() == 2) {
        //         st.pop();
        //     } else {
        //         cout << "NO\n";
        //         return 0;
        //     }
        // }

        // if (s[i] == '}') {
        //     if (st.top() == 3) {
        //         st.pop();
        //     } else {
        //         cout << "NO\n";
        //         return 0;
        //     }
        // }
    }

    cout << "YES\n";
    return 0;
}