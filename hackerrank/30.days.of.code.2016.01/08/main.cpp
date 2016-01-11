// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-8-dictionaries-and-maps
// Day 8: Dictionaries and Maps!

#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

map<string, int> m;

int main() {
    int n; scanf("%d\n", &n);
    string str;
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        int num; scanf("%d\n", &num);
        m[str] = num;
    }

    while (getline(cin, str)) {
        auto it = m.find(str);
        if (it == m.end()) {
            cout << "Not found\n";
        }
        else {
            cout << it->first << "=" << it->second << endl;
        }
    }
    return 0;
}
