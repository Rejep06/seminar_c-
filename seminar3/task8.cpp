#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;

    while (n--) {
        string operation;
        cin >> operation;
        if (operation == "add") {
            int num;
            cin >> num;
            v.push_back(num);
        } else if (operation == "find_if") {
            char c;
            int num;
            cin >> c >> num;
            if (c == '<' || c == '>') {
                for (auto el : v) {
                    if (el == num) continue;
                    if (el < num xor c == '>') cout << el << ' ';
                }
                cout << endl;
            } else {
                cout << "Неправильный ввод операции!\n";
            }
        } else if (operation == "count") {
            char c;
            int num, cnt = 0;
            cin >> c >> num;
            if (c == '%') {
                for (auto el : v) {
                    if (el % num == 0) cnt++;
                }
                cout << cnt << endl;
            } else {
                cout << "Неправильный ввод операции!\n";
            }
        } else if (operation == "print") {
            for (auto el : v) {
                cout << el << ' ';
            }
            cout << endl;
        } else {
            cout << "Такой операции нету!\n";
        }
    }

    return 0;
}