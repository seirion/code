// http://codeforces.com/contest/703/problem/C
#include <iostream>
#include <vector>

using namespace std;

int n, w, bus, speed;
vector<int> x, y;

void input() {
    cin >> n >> w >> bus >> speed;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
}

bool possible_direct() {
    double slop = (double) speed / bus;
    int left(0), right(0);
    for (int i = 0; i < n; i++) {
        if (x[i] < 0) left++;
        else right++;
        double s = (double) y[i] / x[i];
        if (slop < s) return false;
    }
    if (left && right) return false;
    return true;
}

void solve() {
    if (possible_direct()) {
        printf("%0.07f\n", (double) w / speed);
        return;
    }

    double r = 0.0;
HERE:
    double slop = (double) speed / bus;
    double mv = 1e10;
    int mi = -1;
    for (int i = 0; i < n; i++) {
        if (x[i] <= 0) continue;
        double v = (double)y[i] / x[i];
        if (v < mv) {
            mv = v;
            mi = i;
        }
    }

    if (mi == -1 || slop <= mv) {
        printf("%0.07f\n", r + (double) w / speed);
        return;
    }

    r += (double) x[mi] / bus;
    w -= y[mi];

    int X = x[mi];
    int Y = y[mi];
    vector<int> xx, yy;
    for (int i = 0; i < n; i++) {
        if (x[mi] < x[i]) {
            xx.push_back(x[i] - X);
            yy.push_back(y[i] - Y);
        }
    }

    if (xx.empty()) {
        r += (double) w / speed;
        printf("%0.07f\n", r);
        return;
    }

    x.swap(xx);
    y.swap(yy);
    n = x.size();
    goto HERE;
}

int main() {
    input(); solve();
}
