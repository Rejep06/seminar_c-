#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("numbers.txt");
    if (!fin) {
        perror("File opening failed!");
        return EXIT_FAILURE;
    }
    int num, sum = 0;
    while (fin >> num) {
        sum += num;
    }

    cout << sum << endl;
    return 0;
}