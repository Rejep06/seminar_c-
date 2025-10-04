#include <iostream>
#include <string>

using namespace std;

string prefix(string &s1, string &s2) {
    int min_size = min(s1.size(), s2.size());
    for (int i = 0; i < min_size; i++) {
        if (s1[i] != s2[i]) {
            return s1.substr(0, i);
        }
    }
    return s1.substr(0, min_size);
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << prefix(str1, str2) << endl;
    return 0;
}