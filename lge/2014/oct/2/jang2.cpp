// hyungyu.jang@lge.com
// problem 2

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int size;
int in[2000 + 1];
int rank[2000 + 1]; // max rank currently

void count_rank(int index, int from, int to) {
    int num = in[index];
    int result(index);
    for (int i = 1; i < index; i++) {
        if (in[i] > num) {
            result--;
        }
    }
    rank[num] = result % 10007;
}

void print(int from, int to) {
    int result(0);
    int num;
    for (num = from; num <= to; num++) {
        count_rank(num, from, to);
    }
    for (num = 1; num <= size; num++) {
        result += num * rank[num] % 10007;
    }
    printf("%d\n", result % 10007);
}

void solve() {
    scanf("%d", &size);
    int i;
    for (i = 1; i <= size; i++) {
        scanf("%d", &in[i]);
    }
    print(1, size);
    int k;
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        reverse(in + from, in + to + 1);
        print(from, to);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) { solve(); }
    return 0;
}

