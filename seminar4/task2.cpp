#include <deque>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct UserEvent {
    string surname;
    int hour;
    int minute;
    int second;

    UserEvent(string sn, int h, int m, int s) : surname(sn), hour(h), minute(m), second(s) {}
};

class EventQueue {
    deque<UserEvent> userqueue;
    int time;

   public:
    EventQueue() {
        time = 0;
        userqueue = {};
    }

    void addUser(string surname) {
        userqueue.emplace_back(surname, time / 60, time % 60, 0);
        cout << "Пользователь " << surname << " добавень в очередь в ";
        cout << setw(2) << setfill('0') << time / 60 << ":";
        cout << setw(2) << setfill('0') << time % 60 << ":00\n";
    }

    void nextUser() {
        if (userqueue.empty()) {
            cout << "Очередь пуста!\n";
            return;
        }
        UserEvent event = userqueue.front();

        cout << "Обрабатывется пользователь: " << event.surname << endl;
        cout << "Время добавление в очередь: ";
        cout << setw(2) << setfill('0') << event.hour << ":";
        cout << setw(2) << setfill('0') << event.minute << ":";
        cout << setw(2) << setfill('0') << event.second << "\n";

        cout << "Время обработки: ";
        cout << setw(2) << setfill('0') << time / 60 << ":";
        cout << setw(2) << setfill('0') << time % 60 << ":00\n";

        cout << "Время в очереди: " << time - event.hour * 60 - event.minute << " минут\n";

        time += 10;
        userqueue.pop_front();
    }

    void escapeLast() {
        if (userqueue.empty()) {
            cout << "Очередь пуста!\n";
            return;
        }
        UserEvent event = userqueue.front();
        cout << "Пользователь " << event.surname << " покинул очередь.\n";
        cout << "Время в очереди до ухода: " << time - event.hour * 60 - event.minute << " минут.\n";
        userqueue.pop_back();
    }
};

int main() {
    EventQueue eventqueue;
    while (1) {
        string command;
        cin >> command;

        if (command == "add") {
            string surname;
            cin >> surname;
            eventqueue.addUser(surname);
        } else if (command == "next") {
            eventqueue.nextUser();
        } else if (command == "escape") {
            eventqueue.escapeLast();
        } else if (command == "exit") {
            break;
        } else {
            cout << "Неизвестная команда" << endl;
        }
    }
    return 0;
}