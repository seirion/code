// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-6-lets-review
// Day 6: Let's Review!

#include <iostream>
#include <cstring>

using namespace std;


int main() {
    int n; cin >> n;
    char blank[101];
    char sharp[101];
    memset(blank, ' ', sizeof(blank));
    memset(sharp, '#', sizeof(sharp));
    blank[100] = sharp[100] = '\0';

    int i = 1;
    while (--n >= 0) {
        printf("%s%s\n", blank + 100 - n, sharp + 100 - i++);
    }

    return 0;
}
