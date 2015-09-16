// LGE codejam 2015
// 1. ... .
#include <iostream>

using namespace std;

const int MAXN = 500000;
int n;
int ss[MAXN + 1] = {0, };
int num[MAXN + 1] = {0, };

void calc_sum_of_subset() {
    for (int i = 1; i <= MAXN; i++) {
        num[i] = num[i-1] + (ss[i] >= i ? 1 : 0);
        for (int j = i+i; j <= MAXN; j+=i) {
            ss[j] += i;
        }
    }
}

int main() {
    calc_sum_of_subset();
    int query; cin >> query;
    while (query--) {
        int from, to;
        cin >> from >> to;
        cout << num[to] - num[from-1] << endl;
    } 
    return 0;
}
