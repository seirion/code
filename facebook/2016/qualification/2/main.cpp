// https://www.facebook.com/hackercup/problem/1527664744192390/
// Facebook Hacker Cup 2016 Qualification Round
// High Security
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int n;
char in[2][1003];
int c[2][1003] = {0, };
bool used[2][1003] = {false, };

void input() {
    scanf("%d\n", &n);
    fgets(in[0]+1, 1002, stdin);
    fgets(in[1]+1, 1002, stdin);

    in[0][0] = in[1][0] = 'X';
    in[0][n+1] = in[1][n+1] = 'X';
}

int total(int row) {
    int result = 0;
    bool open = false;
    for (int i = 1; i <= n; i++) {
        if (in[row][i] == '.') {
            if (!open) result++;
            open = true;
        }
        else open = false;
        c[row][i] = result;
    }
    return result;
}

int reduce() {
    set<int> s0, s1;
    int result = 0;
    for (int i = 1; i <= c[0][n]; i++) s0.insert(i);
    for (int i = 1; i <= c[1][n]; i++) s1.insert(i);

    for (int i = 1; i <= n; i++) {
        if (in[0][i-1] == 'X' && in[0][i] == '.' && in[0][i+1] == 'X' && in[1][i] == '.') {
            int x = c[1][i];
            auto it = s1.find(x);
            if (it != s1.end()) {
                result++;
                s1.erase(it);
                s0.erase(c[0][i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in[1][i-1] == 'X' && in[1][i] == '.' && in[1][i+1] == 'X' && in[0][i] == '.') {
            int x = c[0][i]; // count part
            auto it = s0.find(x);
            if (it != s0.end()) {
                result++;
                s0.erase(it);
                s1.erase(c[1][i]);
            }
        }
    }

    return result;
}

void solve(int k) {
    int result = total(0) + total(1);
    result -= reduce();

    printf("Case #%d: %d\n", k, result);
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }
    return 0;
}
