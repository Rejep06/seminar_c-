#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

using namespace std;

struct Student {
    string surname;
    int year;
    double score;

    Student() : surname(""), year(0), score(0.0) {}

    Student(const string& s, int y, double sc) : surname(s), year(y), score(sc) {}

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.surname << ' ' << student.year << ' ' << student.score;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student) {
        is >> student.surname >> student.year >> student.score;
        return is;
    }
};

class Database {
    map<string, Student> students;

   public:
    Database() {
        ifstream file("database.txt");
        if (!file.is_open()) {
            cout << "Didn't find database.txt\n";
            return;
        }

        Student student;
        while (file >> student) {
            students[student.surname] = student;
        }

        file.close();
    }

    void addStudent(const Student& student) {
        students[student.surname] = student;
    }

    void updateScore(const string& surname, double newScore) {
        auto it = students.find(surname);
        if (it != students.end()) {
            it->second.score = newScore;
        } else {
            cout << "Didn't find student with surname: " << surname << '\n';
        }
    }

    const Student& operator[](const string& surname) const {
        auto it = students.find(surname);
        if (it != students.end()) {
            return it->second;
        } else {
            cout << "Didn't find student with surname: " << surname << '\n';
            throw out_of_range("Student not found " + surname);
        }
    }

    void removeStudent(const string& surname) {
        auto it = students.find(surname);
        if (it != students.end()) {
            students.erase(it);
        }
    }

    void displayAll() {
        cout << "Students:\n";
        for (auto& pair : students) {
            cout << pair.second << '\n';
        }
        cout << '\n';
    }

    void clear() {
        students.clear();
    }

    vector<Student> getStudentByYear(int year) {
        vector<Student> res;
        for (auto& [surname, student] : students) {
            if (student.year == year) {
                res.push_back(student);
            }
        }
        return res;
    }

    vector<Student> getStudentAboveScore(double minScore) {
        vector<Student> res;
        for (auto& [surname, student] : students) {
            if (student.score >= minScore) {
                res.push_back(student);
            }
        }
        return res;
    }

    ~Database() {
        ofstream file("database.txt");
        if (!file.is_open()) {
            cout << "Didn't find database.txt\n";
            return;
        }

        for (auto& [surname, student] : students) {
            file << student << '\n';
        }

        file.close();
    }
};

int main() {
    Database db;

    db.addStudent(Student("Ivanov", 2020, 8.5));
    db.addStudent(Student("Petrov", 2022, 7.8));
    db.addStudent(Student("Sidorov", 2020, 9.2));
    db.addStudent(Student("Shemsetdinov", 2022, 8.9));

    db.addStudent(Student("Ivanov", 2023, 8.0));

    db.displayAll();

    db.removeStudent("Ivanov");

    db.displayAll();

    db.updateScore("Petrov", 8.3);
    db.updateScore("test", 5.0);

    Student student;
    try {
        student = db["Ivanov"];
    } catch (out_of_range e) {
        cout << e.what() << '\n';
    }
    student = db["Petrov"];
    cout << student << '\n';

    cout << '\n';
    auto students2022 = db.getStudentByYear(2022);
    for (auto st : students2022) {
        cout << st << '\n';
    }
    cout << '\n';

    auto topstudents = db.getStudentAboveScore(8.5);
    for (auto st : topstudents) {
        cout << st << '\n';
    }
    cout << '\n';

    db.clear();

    return 0;
}