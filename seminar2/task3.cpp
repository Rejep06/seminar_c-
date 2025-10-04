#include <iostream>
#include <vector>

using namespace std;

unsigned long long fib(int n, vector<unsigned long long>& dp) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    if (dp.size() > n && dp[n] != 0) {
        return dp[n];
    }

    if (dp.size() <= n) {
        dp.resize(n + 1, 0);
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<unsigned long long> dp = {0, 1};

    cout << fib(n, dp) << endl;
    return 0;
}
