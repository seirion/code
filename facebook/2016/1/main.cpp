// https://www.facebook.com/hackercup/problem/910374079035613/
// Facebook Hacker Cup 2016 Qualification Round
// Boomerang Constellations
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int in[2000][2];

class Line { public:
    int a, b, length;
    Line(int f, int s) : a(f), b(s) {
        int x1(in[a][0]), y1(in[a][1]), x2(in[b][0]), y2(in[b][1]);
        length = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
    bool operator< (const Line &o) const {
        return length < o.length;
    }
};

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i][0] >> in[i][1];
    }
}

long long each(int k) {
    long long result = 0;
    vector<Line> v;

    for (int i = 0; i < n; i++) {
        if (i != k) {
            v.push_back(Line(k, i));
        }
    }
    sort(v.begin(), v.end());

    auto prev = v.begin();
    while (true) {
        auto now = upper_bound(v.begin(), v.end(), *prev);
        int c = now - prev;
        if (2 <= c) {
            result += c * (c-1) / 2;
        }

        if (now == v.end()) break;
        prev = now;
    }

    return result;
}

void solve(int k) {
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += each(i);
    }
    printf("Case #%d: %lld\n", k, result);
}

int main() {
    int c; cin >> c;
    for (int i = 1; i <= c; i++) {
        input();
        solve(i);
    }
    return 0;
}
