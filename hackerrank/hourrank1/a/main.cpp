// https://www.hackerrank.com/contests/hourrank-1/challenges/shafaet-and-array
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, K, L;
vector<int> in;

void input() {
    cin >> n >> K >> L;
    in.resize(n);
    for (int i = 0; i < n; i++) cin >> in[i];
    sort(in.begin(), in.end());
}

int cost_to(vector<int> v, int target) {
    int from(0), to(n-1), cost(0);
    while (from < to) {
        if (v[from] == target) {
            from++;
            continue;
        }
        if (v[to] == target) {
            to--;
            continue;
        }
        if (v[to] < target) break;
        v[from]++; v[to]--; cost += K;
    }

    for (int i = from; i <= to; i++) {
        cost += (target - v[i]) * L;
    }
    return cost;
}

void solve() {
    int sum = accumulate(in.begin(), in.end(), 0);
    int mean = (sum + n - 1) / n;

    int mini = 0x7FFFFFFF;
    for (int i = mean; i <= in[n-1]; i++) {
        mini = min(mini, cost_to(in, i));
    }
    cout << mini << endl;
}

int main() {
    input();
    solve();
    return 0;
}

