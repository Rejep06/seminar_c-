#include <iostream>
#include <map>
#include <string>

using namespace std;

class BiMap {
   private:
    map<string, string> forwardMap;
    map<string, string> backwardMap;

   public:
    void insert(string& key, string& value) {
        forwardMap.insert({key, value});
        backwardMap.insert({value, key});
    }

    string find(string& key) const {
        auto it = forwardMap.find(key);
        if (it == forwardMap.end()) {
            it = backwardMap.find(key);
            if (it == backwardMap.end()) {
                return "";
            }
        }
        return it->second;
    }

    string find_by_value(string& value) const {
        string result = "";
        for (const auto& pair : forwardMap) {
            if (pair.second == value) {
                result += pair.first + " ";
            }
        }
        for (const auto& pair : backwardMap) {
            if (pair.second == value) {
                result += pair.first + " ";
            }
        }
        return result;
    }

    int count_start(char start) const {
        int cnt = 0;
        for (const auto& pair : forwardMap) {
            if (pair.second[0] == start && pair.first[0] == start) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    int n;
    cin >> n;
    BiMap mp;
    while (n--) {
        string operation;
        cin >> operation;
        if (operation == "insert") {
            string s1, s2;
            cin >> s1 >> s2;
            mp.insert(s1, s2);
        } else if (operation == "find") {
            string key;
            cin >> key;
            cout << mp.find(key) << endl;
        } else if (operation == "find_by_value") {
            string value;
            cin >> value;
            cout << mp.find_by_value(value) << endl;
        } else if (operation == "count_start") {
            char start;
            cin >> start;
            cout << mp.count_start(start) << endl;
        } else {
            cout << "Такой операции нету!\n";
        }
    }

    return 0;
}