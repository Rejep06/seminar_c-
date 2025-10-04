#include <iostream>

using namespace std;

bool check(int x)
{
    return (x > 0 && x < 9);
}

int main()
{
    int x1, y1, x2, y2;
    cout << "Введите координаты:\n";
    cin >> x1 >> y1 >> x2 >> y2;

    if (check(x1) & check(x2) & check(y1) & check(y2))
    {
        if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        cout << "Неправильно введен координаты\n";
    }
    return 0;
}
