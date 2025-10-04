#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int k = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) k++;
        }
        cout << k << '\n';
    }
    return 0;
}