// http://algospot.com/judge/problem/read/DARPA
#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
double in[201];

void getInput() {
    cin >> N >> M;
    double temp;
    for (int i = 0; i < M; i++) {
        cin >> in[i];
    }
}

bool canbe(double upper) {
    int from = 0;
    int current = 1;
    int remain = N - 1;
    while (current < M) {
        if (in[current] - in[from] >= upper) {
            if (--remain == 0) return true;
            from = current;
        }
        current++;
    }
    return false;
}

void solve() {
    double low(0.0), high(241.0);
    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2;
        if (canbe(mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    printf("%.02f\n", low);
}

int main() {
    int num;
    cin >> num;
    for (int j = 0; j < num; j++) {getInput(); solve();}
    return 0;
}
