#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    istringstream str(text);
    set<string> words;
    string word;
    while (str >> word) {
        words.insert(word);
    }

    for (auto w : words) {
        cout << w << '\n';
    }

    return 0;
}