// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-8-dictionaries-and-maps
// Day 8: Dictionaries and Maps!

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
char buffer [512];

int main() {
    int n; scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer)-1] = '\0';
        int num; scanf("%d\n", &num);
        m[buffer] = num;
    }

    for (int i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';
        auto it = m.find(buffer);
        if (it == m.end()) {
            cout << "Not found\n";
        }
        else {
            cout << it->first << "=" << it->second << endl;
        }
    }
    return 0;
}
