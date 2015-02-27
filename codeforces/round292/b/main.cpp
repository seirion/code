// http://codeforces.com/contest/515/problem/B
// B. Drazil and His Happy Friends
#include <cstdio>
#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
 
using namespace std;
 
int n, m;
deque<int> nn, mm;
 
void input() {
 
    int i, in, size;
    scanf("%d %d", &n, &m);
    scanf("%d", &size);
    deque<int> temp;
    for (i = 0; i < size; i++) {
        scanf("%d", &in);
        temp.push_back(in);
    }
    sort(temp.begin(), temp.end());
    for (i = 0; i < n; i++) {
        if (!temp.empty() && temp.front() == i) temp.pop_front();
        else nn.push_back(i);
    }
 
    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        scanf("%d", &in);
        temp.push_back(in);
    }
    sort(temp.begin(), temp.end());
    for (i = 0; i < m; i++) {
        if (!temp.empty() && temp.front() == i) temp.pop_front();
        else mm.push_back(i);
    }
}
 
int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

bool possible() {
    int limit = lcm(n, m) * 2;
    while (!nn.empty() && !mm.empty()) {
        if (nn.front() > limit || mm.front() > limit) {
            return false;
        }
        int i = nn.front();
        int j = mm.front();
        if (i == j) {
            nn.push_back(i + n); mm.push_back(j + m);
            nn.pop_front(); mm.pop_front();
        }
        else if (i < j) {
            nn.pop_front();
        }
        else {
            mm.pop_front();
        }
    }
 
    return true;
}
 
int main() {
    input();
    printf("%s\n", possible() ? "Yes" : "No");
    return 0;
}
