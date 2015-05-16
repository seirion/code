// https://algospot.com/judge/problem/read/ENCODING
#include <cstdio>
#include <cstdlib>
#include <cstring>
 
using namespace std;
 
int row, col;
char in[120];
bool out[500];
char *cur;
 
enum {
    RIGHT, DOWN, LEFT, UP,
};
 
void input() {
    fgets(in, 120, stdin);
    cur = in;
    row = atoi(cur);
    while (*cur != ' ') cur++;
    cur++;
    col = atoi(cur);
    while (*cur != ' ') cur++;
    cur++;
}
 
void fill(bool *str, char c) {
    for (int i(0), p(4); i < 5; i++, p--) {
        str[i] = ((c-'A'+1) & (1 << p));
    }
}
 
int fill_out(bool *str, bool **org, int begin, int jump, int size) {
    int index = begin;
    for (int i = 0; i < size; i++, index += jump) {
        str[index] = **org;
        (*org)++;
    }
    return index - jump;
}
 
void print(bool *s, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", s[i]);
    }
    printf("\n");
}
 
void solve() {
    memset(out, 0, sizeof(bool) * 500);
    int direct = RIGHT;
    int limit [] = { col, row - 1 };
    int jump [] = {1, col, -1, -col};
    bool temp [500] = {false, };
 
    int length = strlen(cur) - 1; // ignore \n
    for (int s(0), i(0); i < length; i++, s += 5) {
        if (cur[i] != ' ') fill(temp+s, cur[i]);
    }
 
    int index = -1;
    bool *ttemp = temp;
    while (ttemp - temp < sizeof(bool) * row * col) {
        index = fill_out(out, &ttemp, index + jump[direct], jump[direct], limit[direct & 1]);
        limit[direct & 1]--;
        direct = (direct + 1) % 4;
    }
    print(out, row * col);
}
 
int main() {
    int num;
    scanf("%d\n", &num);
    for (int i = 1; i <= num; i++) {
        input();
        printf("%d ", i);
        solve();
    }
    return 0;
}
