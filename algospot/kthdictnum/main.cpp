// http://algospot.com/judge/problem/read/KTHDICTNUM
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long uint64;

uint64 from, to, k;

uint64 num_of_children(uint64 prefix, int digit) { // depth first search

    if (prefix == 0) return (from == 0 ? 1 : 0);

    uint64 all(0), num(1);

    for (int len = digit; len <= 19; len++) { // 2^63-1 ==  9,223,372,036,854,775,807
                                          // 2^64-1 == 18,446,744,073,709,551,615
        uint64 begin = prefix * num;
        uint64 end = begin + num; // [begin, end)
        if (begin >= to) break;

        begin = max(begin, from);
        end = min(end, to);

        if (end > begin) {
            all += (end - begin);
        }
        num *= 10;
    }
    return all;
}

uint64 next(uint64 prefix, int digit) {
    for (int head = 0; head <= 9; head++) {
        uint64 all = num_of_children(prefix * 10 + head, digit);
        if (all >= k) return head;
        else k -= all;
    }

    printf("something wrong...\n");
    return 0;
}

uint64 find(uint64 prefix) {
    int digit = 1;
    uint64 solution = 0;
    do {
        solution = solution * 10 + next(solution, digit++);
        if (from <= solution && solution < to) k--;
    } while (k > 0);
    return solution;
}

void solve() {
    cin >> from >> to >> k;
    to++; // [from, to) 
    k++;  // 1-based

    cout << find(0) << endl;
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve(); }
    return 0;
}
