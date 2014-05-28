// http://algospot.com/judge/problem/read/DARPA
#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
double in[201];

void getInput() {
    cin >> N >> M;
    for (int j = 0; j < M; j++) {
        cin >> in[j];
    }
}

bool canbe(double upper) {
    int from = 0;
    int current = 1;
    int remain = N - 1;
    while (current < M) {
        if (in[current] - in[from] >= upper) {
            if (--remain == 0) {
                return true;
            }
            from = current;
        }
        current++;
    }
    return false;
}

void solve() {
    int i, adj;
    double d = 0.0;
    double solution;
    for (i = 0; i < 24000; i++) {
        d = 0.01 * i;
        if (canbe(d)) {
            solution = d;
        }
        else break;
    }
    printf("%.02f\n", solution);
}

int main() {
    int num;
    cin >> num;
    for (int j = 0; j < num; j++) {getInput(); solve();}
    return 0;
}
