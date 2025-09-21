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
    array<int, 5> fives;
}