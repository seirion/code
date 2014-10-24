// http://algospot.com/judge/problem/read/BRACKETS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char in[101];
int memo[100][100];

int find_next(int from, int to, char c) {
    for (int i = from; i <= to; i++) {
        if (in[i] == c) return i;
    }
    return -1;
}

int count_max(int from, int to) {
    if (from >= to) return 0;
    if (memo[from][to] != -1) return memo[from][to];

    int &count = memo[from][to];
    count = 0;

    if (in[from] == '(' || in[from] == '[') {
        char closer = in[from] == '(' ? ')' : ']';
        int start = from + 1;
        while (true) { // on
            int last = find_next(start, to, closer);
            if (last == -1) break;
            int temp = 2 + count_max(from+1, last-1) + count_max(last+1, to);
            count = max(count, temp);
            start = last + 1;
        }
        count = max(count, count_max(from + 1, to)); // off
    }
    else {
        count = count_max(from + 1, to); // off
    }
    return count;
}

void solve() {
    memset(memo, 0xFF, sizeof(int) * 100 * 100);
    int size = strlen(in);
    printf("%d\n", count_max(0, size-1));
}

int main() {
    while (true) {
        gets(in);
        if (strcmp(in, "end") == 0) break;
        solve();
    }
    return 0;
}
