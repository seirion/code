// https://code.google.com/codejam/contest/4224486/dashboard#s=p1
// Problem B. Haircut

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long int64;

int B, N;
int M[1000];

void input() {
    cin >> B >> N;
    for (int i = 0; i < B; i++) {
        cin >> M[i];
    }
}

int solve() {
    int64 num, low(0), high(1e15);

    while (low < high) {
        num = 0;
        int64 mid = (high + low) >> 1;
        for (int i = 0; i < B; i++) {
            num += mid / M[i] + 1;
        }
        if (num >= N) high = mid;
        else low = mid + 1;
    }

    num = 0;
    vector<int> cand;
    for (int i = 0; i < B; i++) {
        num += high / M[i] + 1;
        if (high % M[i] == 0) cand.push_back(i);
    }
    return cand[cand.size()-1 -(num-N)] + 1;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        printf("Case #%d: %d\n", i, solve());
    }
}

