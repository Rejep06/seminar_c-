#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Bus {
   private:
    int number;
    unordered_set<string> stops;

   public:
    Bus(int num) : number(num) {}

    int get_number() const { return number; }
    const unordered_set<string>& get_stops() const { return stops; }

    void set_stops(const unordered_set<string>& st) {
        stops.clear();
        stops.insert(st.begin(), st.end());
    }

    void add_stop(const string& stop) {
        if (visits_stop(stop)) return;
        stops.insert(stop);
    }

    void remove_stop(const string& stop) {
        stops.erase(stop);
    }

    bool visits_stop(const string& stop) const {
        return stops.find(stop) != stops.end();
    }
};

class BusStop {
   private:
    string name;
    unordered_set<int> buses;

   public:
    BusStop(string nm) : name(nm) {}

    const string& get_name() const { return name; }
    const unordered_set<int>& get_buses() const { return buses; }

    void set_buses(const unordered_set<int>& bs) {
        buses.clear();
        buses.insert(bs.begin(), bs.end());
    }

    void add_bus(int bus) {
        if (is_served(bus)) return;
        buses.insert(bus);
    }

    void remove_bus(int bus) {
        buses.erase(bus);
    }

    bool is_served(int bus) const {
        return buses.find(bus) != buses.end();
    }
};

class BusSystem {
   private:
    unordered_map<int, Bus> buses;
    unordered_map<string, BusStop> stops;

   public:
    bool add_bus(int bus) {
        if (buses.find(bus) != buses.end()) return 0;
        buses.emplace(bus, Bus(bus));
        return 1;
    }

    bool add_stop(const string& stop) {
        if (stops.find(stop) != stops.end()) return 0;
        stops.emplace(stop, BusStop(stop));
        return 1;
    }

    bool connect_bus_to_stop(int bus, string stop) {
        auto bus_it = buses.find(bus);
        auto stop_it = stops.find(stop);

        if (bus_it == buses.end() || stop_it == stops.end()) return 0;
        bus_it->second.add_stop(stop_it->second.get_name());
        stop_it->second.add_bus(bus_it->second.get_number());
        return 1;
    }

    bool disconnect_bus_to_stop(int bus, string stop) {
        auto bus_it = buses.find(bus);
        auto stop_it = stops.find(stop);

        if (bus_it == buses.end() || stop_it == stops.end()) return 0;
        bus_it->second.remove_stop(stop_it->second.get_name());
        stop_it->second.remove_bus(bus_it->second.get_number());
        return 1;
    }

    unordered_set<string> get_stops_for_bus(int bus) const {
        auto it = buses.find(bus);
        if (it == buses.end()) {
            return {};
        }
        return it->second.get_stops();
    }

    unordered_set<int> get_buses_for_stop(const string& stop) const {
        auto it = stops.find(stop);
        if (it == stops.end()) {
            return {};
        }
        return it->second.get_buses();
    }

    unordered_set<string> find_rechable_stops(const string& stop) {
        auto it = stops.find(stop);
        if (it == stops.end()) {
            return {};
        }
        unordered_set<int> buses_for_stop = it->second.get_buses();
        unordered_set<string> result;

        for (auto bus : buses_for_stop) {
            auto bus_it = buses.find(bus);
            if (bus_it == buses.end()) continue;
            auto stops_for_bus = bus_it->second.get_stops();
            result.insert(stops_for_bus.begin(), stops_for_bus.end());
        }
        return result;
    }
};

// class BusSystem {
//    private:
//     unordered_map<int, unordered_set<string>> busToStops;
//     unordered_map<string, unordered_set<int>> stoptToBusses;
//    public:
//     void add_bus(int bus, unordered_set<string> busStops) {
//         busToStops[bus] = busStops;
//         for (auto stop : busStops) {
//             stoptToBusses[stop].insert(bus);
//         }
//     }
//     void add_stop_for_bus(int bus, string stop) {
//         busToStops[bus].insert(stop);
//         stoptToBusses[stop].insert(bus);
//     }
//     unordered_set<string> get_stops(int bus) {
//         return busToStops[bus];
//     }
//     unordered_set<int> get_busses(string stop) {
//         return stoptToBusses[stop];
//     }
//     unordered_set<string> from_stop_to_stops(string stop) {
//         unordered_set<string> stops;
//         for (auto bus : stoptToBusses[stop]) {
//             stops.insert(busToStops[bus].begin(), busToStops[bus].end());
//         }
//         return stops;
//     }
// };

int main() {
    BusSystem bussystem;
    int n;
    cin >> n;
    string emptys;
    getline(cin, emptys);
    for (int i = 0; i < n; i++) {
        string str;
        int bus;
        getline(cin, str);
        stringstream ss(str);
        ss >> bus;
        bussystem.add_bus(bus);
        string stop;
        while (ss >> stop) {
            bussystem.add_stop(stop);
            bussystem.connect_bus_to_stop(bus, stop);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        string operation;
        cin >> operation;
        if (operation == "get_stops") {
            int bus;
            cin >> bus;
            const unordered_set<string>& stops = bussystem.get_stops_for_bus(bus);
            for (auto stop : stops) {
                cout << stop << ' ';
            }
            cout << "\n\n";
        } else if (operation == "get_buses") {
            string stop;
            cin >> stop;
            const unordered_set<int>& buses = bussystem.get_buses_for_stop(stop);
            for (auto bus : buses) {
                cout << bus << ' ';
            }
            cout << "\n\n";
        } else if (operation == "rechable_stops") {
            string stop;
            cin >> stop;
            const unordered_set<string>& rechable_stops = bussystem.find_rechable_stops(stop);
            for (auto stop : rechable_stops) {
                cout << stop << ' ';
            }
            cout << "\n\n";
        } else {
            cout << "Такой операции нету!\n";
        }
    }
    return 0;
}