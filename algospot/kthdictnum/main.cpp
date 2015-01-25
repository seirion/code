// http://algospot.com/judge/problem/read/KTHDICTNUM
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long uint64;

uint64 from, to, k;

int where_am_i(uint64 prefix) {
    uint64 num;
    uint64 acc(0), sum(0);
    for (int head = 0; head <= 9; head++) { // [0, 9]
        num = 1;
        for (int len = 0; len < 19; len++) { // 2^63-1 == 4611686018427387904
            uint64 begin = (prefix * 10 + head) * num;
            uint64 end = begin + num; // [begin, end)
            if (begin > to) break;

            begin = max(begin, from);
            end = min(end, to);

            if (end > begin) sum += end - begin;
            if (prefix == 0 && head == 0) break;
            num *= 10;
        }
        if (sum > k) {
            k -= acc;
            return head;
        }
        acc = sum;
    }
    printf("somethin's wrong >>>> \n");
    return -1ll;
}

uint64 find(uint64 prefix) {
    // 1. where am i ?
    while (true) {
        prefix = (prefix * 10) + where_am_i(prefix);
        if (from <= prefix && prefix < to) {
            if (k == 0) return prefix;
            k--;
        }
    }
}


void solve() {
    scanf("%lld %lld %lld", &from, &to, &k);
    to++;

    printf("%lld\n", find(0)); // [from, to)
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve(); }
    return 0;
}
