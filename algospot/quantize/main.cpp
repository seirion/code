// http://algospot.com/judge/problem/read/QUANTIZE
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int n; // input num
int s;
int in[100];
int sum[100];
int sumsq[100]; // square
int memo[100][11];

void getInput() {
    int i;
    cin >> n >> s;
    for (i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in, in + n);

    sum[0] = in[0];
    sumsq[0] = in[0] * in[0];

    for (i = 1; i < n; i++) {
        sum[i] = sum[i-1] + in[i];
        sumsq[i] = sumsq[i-1] + (in[i] * in[i]);
    }

    memset(memo, 0xFF, sizeof(int) * 100 * 11); // -1
}

int errorValue(int from, int to) { // [from, to]
    int total = sum[to] - (from == 0 ? 0 : sum[from-1]);
    int sq = sumsq[to] - (from == 0 ? 0 : sumsq[from-1]);
    int avg = (int)((double)total / (to - from + 1) + .5);

    return sq - (2 * avg * total) + (avg * avg *(to - from + 1));
}


int quantize(int from, int part) {
    if (from == n) return 0;
    if (part == 0) return 0x00FFFFFF;

    int &v = memo[from][part];
    if (v != -1) return v;

    v = 0x00FFFFFF;
    for (int to = from; to < n; to++) {
        v = min(v, errorValue(from, to) + quantize(to + 1, part-1));
    }

    return v;
}

void solve() {
    cout << quantize(0, s) << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
