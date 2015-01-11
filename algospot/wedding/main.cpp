// http://algospot.com/judge/problem/read/WEDDING
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;
typedef long long int64;

int N;
int R; // retirement
int A[1000]; // age
int S[1000]; // salery
int D[1000]; // change rate

int64 memo[2000][4001];

void input() {
    scanf("%d %d", &N, &R);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &A[i], &S[i], &D[i]);
    }
}

int64 calc(int who, int when) {
    if (A[who] >= R) { // already retired
        return (int64)S[who];
    }

    int64 age = A[who] + when;
    if (age < R) {
        return (int64)S[who] + (int64)D[who] * when;
    }
    else { // age >= R
        return (int64)S[who] + (int64)D[who] * (R - 3 - A[who]);
    }
}

void solve() {
    memset(memo, 0, sizeof(int64) * 2000 * 4001);
    set<int> seg_set;
    int i;
    for (i = 0; i < N; i++) {
        if (A[i] < R) {
            seg_set.insert(R - A[i] - 1); // previous
            seg_set.insert(R - A[i]); // retirement
        }
    }
    seg_set.insert(0); // start point

    int seg_size = seg_set.size();
    int segment[4001];

    set<int>::const_iterator it = seg_set.begin();
    for (i = 0; it != seg_set.end(); i++, it++) {
        segment[i] = *it;
    }

    for (i = 0; i < N; i++) {
        for (int j = 0; j < seg_size; j++) {
            memo[i][j] = calc(i, segment[j]);
        }
    }

    int64 maxi = 0;
    for (i = 0; i < seg_size; i++) {
        int64 sum = 0;
        for (int j = 0; j < N; j++) {
            sum += memo[j][i];
        }
        maxi = max(maxi, sum);
    }

    printf("%0.03f\n", (double)maxi / 1000);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
