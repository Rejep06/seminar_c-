#include <iostream>

using namespace std;

class LimitedInt {
    int min, max, value;
    static int changes;

    bool isValid(int value_) const {
        return (min <= value_ && value_ <= max);
    }

   public:
    LimitedInt(int value_, int min_, int max_) : min(min_), max(max_) {
        if (!isValid(value_)) {
            throw out_of_range("Value is out of range!");
        }
        value = value_;
    }

    operator int() const {
        return value;
    }

    int operator[]() const {
        return value;
    }

    int operator[](int value_) {
        if (isValid(value_)) {
            value = value_;
            changes++;
        }
        return value;
    }

    static int getCount() {
        return changes;
    }
};

int LimitedInt::changes = 0;

int main() {
    LimitedInt num1(5, 0, 10);

    cout << num1[] << '\n';
    cout << num1[10] << '\n';
    cout << num1[100] << '\n';
    cout << int(num1) << '\n';

    try {
        LimitedInt num2(-1, 0, 1);
    } catch (out_of_range e) {
        cout << e.what() << '\n';
    }

    cout << "Количество успешных изменений:" << LimitedInt::getCount() << '\n';
    return 0;
}