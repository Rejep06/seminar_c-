#include <fstream>
#include <iostream>

using namespace std;

class FileGuard {
    ofstream myFile;

   public:
    FileGuard(const string& path) {
        myFile.open(path);
        if (!myFile.is_open()) {
            throw runtime_error("File couldn't be open!");
        }
    }

    ~FileGuard() {
        myFile.close();
    }

    void Write(const string& text) {
        myFile << text;
    }
};

int main() {
    string path = "text.txt";
    string text;
    cin >> text;
    FileGuard myfile(path);
    myfile.Write(text);
    // FileGuard copy = myfile;
    // copy.Write("Hi");

    try {
        FileGuard testFile("/invalid/path/file.txt");
        testFile.Write("This won't execute");
    } catch (runtime_error e) {
        cout << e.what() << '\n';
    }
    return 0;
}