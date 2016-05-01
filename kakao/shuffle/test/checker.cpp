#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

const string in = "result.txt";

int main() {
    set<string> artist;
    string prev;
    int total = 0;
    bool checked = true;

    ifstream file(in);
    string line;
    while (getline(file, line)) {
        string data;
        stringstream stream(line);
        while (getline(stream, data, '\t')) {
            total++;
            artist.insert(data);
            if (prev == data) {
                //cout << "faled :: " << total << endl;
                checked = false;
            }
            prev = data;
        }
    }


    cout << "number of songs : " << total << endl;
    cout << "number of artist : " << artist.size() << endl;
    cout << "result : " << (checked ? "success\n" : "fail\n");
}
