#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Time {
    int hour, minute, second;

    Time() : hour(0), minute(0), second(0) {}

    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    Time operator-(Time& other) const {
        int newSecond = second + hour * 3600 + minute * 60;
        newSecond -= other.second + other.minute * 60 + other.hour * 3600;
        if (newSecond < 0) {
            return Time();
        }
        return Time(newSecond / 3600, (newSecond % 3600) / 60, newSecond % 60);
    }

    friend ostream& operator<<(ostream& os, const Time& time) {
        os << time.hour << ':' << time.minute << ':' << time.second;
        return os;
    }

    friend istream& operator>>(istream& is, Time& time) {
        is >> time.hour >> time.minute >> time.second;
        return is;
    }

    auto operator<=>(const Time& other) const {
        int seconds1 = second + minute * 60 + hour * 3600;
        int seconds2 = other.second + other.minute * 60 + other.hour * 3600;
        return seconds1 <=> seconds2;
    }
};

struct Flight {
    int Id;
    string arrivalAirport, departureAirport;
    Time arrivalTime;

    Flight(int id, string ar, string dp, Time time) : Id(id), arrivalAirport(ar), departureAirport(dp), arrivalTime(time) {}

    auto operator<=>(Flight& other) {
        return arrivalTime <=> other.arrivalTime;
        // return Id <=> other.Id;
    }

    friend ostream& operator<<(ostream& os, const Flight& flight) {
        os << flight.Id << ' ' << flight.arrivalAirport << ' ' << flight.departureAirport << ' ' << flight.arrivalTime;
        return os;
    }
};

void Board(const vector<Flight>& flights, const string& airport) {
    for (auto flight : flights) {
        if (flight.departureAirport == airport) {
            cout << flight << '\n';
        }
    }
    for (auto flight : flights) {
        if (flight.arrivalAirport == airport) {
            cout << flight << '\n';
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<Flight> flights;

    for (int i = 0; i < n; i++) {
        int id;
        string ar, dp;
        Time time;
        cin >> id >> ar >> dp >> time;
        flights.emplace_back(id, ar, dp, time);
    }

    sort(flights.begin(), flights.end());
    string airport;
    cin >> airport;
    cout << "|===================================|\n";
    Board(flights, airport);
    return 0;
}