#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main() {
    srand (time(nullptr));

    ofstream a("artist.txt");
    ofstream p("playlist.txt");
    for (int i = 0; i < 1000; i++) {
        int art = rand() % 2;
        a << art << "\t";
        p << art << "\t";
    }
}
