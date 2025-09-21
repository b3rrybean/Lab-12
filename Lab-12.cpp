#include <iostream>
#include <fstream>
#include <array>
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
}