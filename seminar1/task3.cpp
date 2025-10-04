#include <iostream>

using namespace std;

int absolut(int a, int b)
{
	int diff = a - b;
	int sign = (diff >> 31) & 1;
	return (diff * (1 - 2 * sign));
}

int main()
{
	int a, b;
	cin >> a >> b;

	int ans = (a + b - absolut(a, b)) / 2;
	cout << ans << '\n';
	return 0;
}