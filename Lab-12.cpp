#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;

const int SIZE = 30;

int main() {
    array<int, SIZE> temps;
    ifstream file("temps.txt");
    if (!file) {
        cout << "Error opeing file.\n";
        return 1;
    }
    for (int i = 0; i < SIZE; i++) file >> temps[i];
    file.close();

    // Basic info
    cout << "Array size: " << temps.size() << endl;
    cout << "First element: " << temps.front() << endl;
    cout << "Last element: " << temps.back() << endl;
    cout << "Element at index 5: " << temps.at(5) << endl;
    cout << "Is empty? " << (temps.empty() ? "Yes" : "No") << endl;
    cout << "Data address: " << temps.data() << endl;

    // Sort ascending
    sort(temps.begin(), temps.end());
    cout << "Sorted temps: ";
    for (int t : temps) cout << t << " ";
    cout << endl;

    // Sort descending
    sort(temps.rbegin(), temps.rend());
    cout << "Reverse sorted temps: ";
    for (int t : temps) cout << t << " ";
    cout << endl;

    // Find a specific value
    int target = 90;
    auto it = find(temps.begin(), temps.end(), target);
    if (it != temps.end())
        cout << target << " found at index " << (it - temps.begin()) << endl;
    else
        cout << target << " not found.\n";

    // Fill and swap arrays
    array<int, 4> fours;
    array<int, 4> fives;
    fours.fill(4);
    fives.fill(5);

    cout << "\nBefore swap, fours: ";
    for (int v : fours) cout << v << " ";
    cout << endl;

    fours.swap(fives);
    cout << "After swap, fours: ";
    for (int v : fours) cout << v << " ";
    cout << endl;

    // 2D array
    array<int, 3> week1 = {72, 75, 78};
    array<int, 3> week2 = {80, 83, 85};
    array<array<int, 3>, 2> month = {week1, week2};

    cout << "\n2D array element [1][2]: " << month[1][2] << endl;

    // Simulation: hot/cold days
    int hotDays = count_if(temps.begin(), temps.end(), [](int t){ return t > 80;});
    int coldDays = count_if(temps.begin(), temps.end(), [](int t){ return t < 60});

    cout << "\nHot days (>80): " << hotDays << endl;
    cout << "Cold days (<60): " << coldDays << endl;

    return 0;
}