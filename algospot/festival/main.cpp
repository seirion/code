// http://algospot.com/judge/problem/read/FESTIVAL
#include <iostream>
#include <cstdio>

using namespace std;

int n, l;
int cost [1001];

void getInput() {
    cin >> n >> l;
    cost[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> cost[i+1];
        cost[i+1] += cost[i];
    }
}

void solve() {
    int to = n - l + 1;
    double mini = 30000000.0;

    // calculate
    for (int i = 1; i <= to; i++) {
        for (int j = l; i + j - 1 < n + 1; j++) {
            double x = (double)(cost[i+j-1] - cost[i-1]) / j;
            mini = min(mini, x);
        }
    }

    printf("%.08lf\n", mini);
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
