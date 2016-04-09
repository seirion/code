// https://code.google.com/codejam/contest/6254486/dashboard#s=p1
// Problem B. Revenge of the Pancakes
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int solve() {
    string in; cin >> in;
    
    char now = in[0];
    int result = 0;
    int size = in.size();
    for (int i = 1; i < size; i++) {
        if (now != in[i]) {
            now = in[i];
            result++;
        }
    }

    if (now == '-') result++;
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
}

