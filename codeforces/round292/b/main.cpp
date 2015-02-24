// http://codeforces.com/contest/515/problem/B
// B. Drazil and His Happy Friends
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
 
using namespace std;
 
int n, m;
queue<int> nn, mm;
 
void input() {
 
    int i, in, size;
    scanf("%d %d", &n, &m);
    scanf("%d", &size);
    queue<int> temp;
    for (i = 0; i < size; i++) {
        scanf("%d", &in);
        temp.push(in);
    }
    for (i = 0; i < n; i++) {
        if (temp.front() == i) temp.pop();
        else nn.push(i);
    }
 
    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        scanf("%d", &in);
        temp.push(in);
    }
    for (i = 0; i < m; i++) {
        if (temp.front() == i) temp.pop();
        else mm.push(i);
    }
}
 
int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

bool possible() {
    int limit = lcm(n, m);
    while (!nn.empty() && !mm.empty()) {
        if (nn.front() > limit || mm.front() > limit) {
            return false;
        }
        int i = nn.front();
        int j = mm.front();
        if (i == j) {
            nn.push(i + n); mm.push(j + m);
            nn.pop(); mm.pop();
        }
        else if (i < j) {
            nn.pop();
        }
        else {
            mm.pop();
        }
    }
 
    return true;
}
 
int main() {
    input();
    printf("%s\n", possible() ? "Yes" : "No");
    return 0;
}
