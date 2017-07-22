#include <iostream>
#include <set>
#include <functional>

using namespace std;

set<int, greater<int>> a, b;
pair<int, int> best;
int best_gcd = 1;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int gcd(pair<int, int> &p) {
    return gcd(p.first, p.second);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) { int x; cin >> x; a.insert(x); }
    for (int i = 0; i < n; i++) { int x; cin >> x; b.insert(x); }

    best = make_pair(*a.begin(), *b.begin());
    best_gcd = gcd(best);

    for (int x : a) {
        if (best_gcd > x) break;

        for (int y : b) {
            if (best_gcd > y) break;
            int g = gcd(x, y);
            if (best_gcd == g && (best.first + best.second) < (x + y)) {
                best = make_pair(x, y);
                best_gcd = g;
            } else if (best_gcd < g) {
                best = make_pair(x, y);
                best_gcd = g;
            }
        }
    }

    cout << best.first + best.second << endl;
    return 0;
}
