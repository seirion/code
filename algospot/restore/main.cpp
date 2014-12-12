// https://www.algospot.com/judge/problem/read/RESTORE
#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int n;
char str[15][41];
int memo[15][1 << 15]; // length
int overlap[15][15];
 
void input() {
    memset(memo, 0, sizeof(int) * 15 * (1<<15));
    memset(overlap, 0, sizeof(int) * 15 * 15);
 
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        gets(str[i]);
    }
}
 
void check_fully_overlap() {
    int i, all = (1 << n) - 1;
    for (i = 0; i < n; i++) {
        if (!(all & (1 << i))) continue;
        for (int j = 0; j < n; j++) {
            if (i != j && all & (1 << j) && strstr(str[i], str[j])) {
                all &= ~(1<<j);
            }
        }
    }
    n = __builtin_popcount(all);
    i = 0;
    while (all) {
        int cur = __builtin_ctz(all);
        all &= all - 1;
        if (i != cur) strcpy(str[i], str[cur]);
        i++;
    }
}
 
int count(int from, int to) {
    int from_len = strlen(str[from]);
    int to_len = strlen(str[to]);
    int i = min(from_len, to_len);
    char *fstr = str[from] + from_len - i;
    for (; i > 0; i--, fstr++) {
        if (strncmp(fstr, str[to], i) == 0) break;
    }
    return i;
}
 
int build_overlap(int all) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { // i -> j
            if (i == j) continue;
            memo[i][1<<j] = overlap[i][j] = count(i, j);
        }
    }
}
 
int cal_value(int from, int to) {
    int m(0), temp(to);
    while (temp) {
        int i = __builtin_ctz(temp);
        temp &= temp - 1;
        m = max(m, overlap[from][i] + memo[i][to & ~(1<<i)]);
    }
    return m;
}
 
void print(int from, int to) {
    int index(-1), value(-1), temp(to);
    while (temp) {
        int i = __builtin_ctz(temp);
        temp &= temp - 1;
        int m = overlap[from][i] + memo[i][to & ~(1 << i)];
        if (m > value) {
            value = m; index = i;
        }
    }

    printf("%s", str[index] + overlap[from][index]);
    to = to & ~(1 << index);
    if (to) print(index, to);
}

void solve() {
    check_fully_overlap();
    const int all = (1 << n) - 1;
    build_overlap(all);
    
    for (int to = 3; to < all; to++) {
        for (int from = 0; from < n; from++) {
            if (to & (1<<from) || memo[from][to] > 0) continue;
            memo[from][to] = cal_value(from, to);
        }
    }
 
    int index(-1), value(-1);
    for (int from = 0; from < n; from++) {
        int m = memo[from][all & ~(1<<from)];
        if (m > value) {
            value = m; index = from;
        }
    }
    printf("%s", str[index]);
    print(index, all & ~(1 << index));
    printf("\n");
}
 
int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
