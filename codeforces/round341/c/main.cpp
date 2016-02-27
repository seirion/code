//
#include <iostream>
#include <cstdio>

using namespace std;

int n, p;
int in[100000][2];
double pro[100000];

int num(int x) {
    return x / p;
}

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> in[i][0] >> in[i][1];

    for (int i = 0; i < n; i++) {
        int x = num(in[i][1]) - num(in[i][0]-1);
        int range = in[i][1] - in[i][0] + 1;

        pro[i] = (double)x / range;
    }

    double r = .0;
    for (int i = 0; i < n; i++) {
        r += pro[i] * 4000; // o
        r += (1-pro[i]) * pro[(i+1)%n] * pro[(i+n-1)%n] * 4000;// x o o
        r += (1-pro[i]) * (1-pro[(i+1)%n]) * pro[(i+n-1)%n] * 2000;// x x o
        r += (1-pro[i]) * pro[(i+1)%n] * (1-pro[(i+n-1)%n]) * 2000;// x o x
    }

    printf("%.8f\n", r / 2);
    return 0;
}
