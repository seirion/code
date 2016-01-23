// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-20-review-plus-more-string-methods
// Day 20: Review + More String Methods!

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

char str[400004];

int main() {
    vector<string> result;
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';

    string delimiter(" ![,?.\\_'@+]");

    char *pch;
    pch = strtok (str, delimiter.c_str());
    while (pch) {
        result.push_back(pch);
        pch = strtok (0, delimiter.c_str());
    }

    cout << result.size() << endl;
    for (string &s : result) cout << s << endl;
    return 0;
}
