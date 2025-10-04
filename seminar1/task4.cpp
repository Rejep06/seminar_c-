#include <iostream>
#include <stdexcept>

using namespace std;

int calculate_operation(int a, int b, int choice)
{
    switch (choice)
    {
    case 1:
        return a + b;
    case 2:
        return a - b;
    case 3:
        return a * b;
    case 4:
        return a & b;
    default:
        throw invalid_argument("Неверная операция!");
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    int choice = 0;
    while (choice > 4 || choice <= 0)
    {
        cout << "Выберите операцию:\n";
        cout << "1 - сумма\n";
        cout << "2 - разность\n";
        cout << "3 - произведение\n";
        cout << "4 - побитовое операция 'И'\n";
        cin >> choice;
    }
    try
    {
        cout << calculate_operation(a, b, choice) << '\n';
    }
    catch (const exception &e)
    {
        cout << e.what() << '\n';
    }
}