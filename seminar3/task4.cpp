#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool find_nouns(string_view& str) {
    size_t left = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            if (i - left >= 2 && isupper(str[left])) {
                str = str.substr(left, i - left);
                return true;
            }
            left = i + 1;
        }
    }
    if (str.size() - left >= 2 && isupper(str[left])) {
        str = str.substr(left, str.size() - left);
        return true;
    }
    return false;
}

int main() {
    string s;
    getline(cin, s);
    string_view ans = s;
    if (find_nouns(ans)) {
        cout << ans << endl;
    } else {
        cout << "Not found!\n";
    }
    return 0;
}