// World CodeSprint
// Mars Exploration
// https://www.hackerrank.com/contests/worldcodesprint/challenges/save-our-ship
#include <iostream>
#include <string>

using namespace std;

int main() {
    string org("SOS");
    string s;
    cin >> s;

    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != org[i%3]) r++;
    }
    cout << r << endl;
    return 0;
}
