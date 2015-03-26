// http://algospot.com/judge/problem/read/PALINDROMIZE
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char in[100 * 1000 + 1]; // input string
char rev[100 * 1000 + 1]; // reverse
int pre[100 * 1000 + 1] = { 0, }; // pre-processed

void make_table(int size) {
    memset(pre, 0, sizeof(int) * ((100 * 1000)/2 + 1));

    int i(1), match(0);
    while (i + match < size) {
        if (rev[i + match] == rev[match]) {
            match++;
            pre[i + match - 1] = match;
        }
        else {
            if (match == 0) {
                i++;
            }
            else {
                i += match - pre[match - 1];
                match = pre[match - 1];
            }
        }
    }
}

int find_match(int size) {
    int start(0);

    int i(0), match(0);
    while (i + match < size) {
        if (in[i + match] == rev[match]) {
            match++;
            if (match == size - i) return i;
        }
        else {
            if (match == 0) {
                i++;
            }
            else {
                i += match - pre[match - 1];
                match = pre[match - 1];
            }
        }
    }
}

void solve() {
    gets(in);
    int size = strlen(in);
    strcpy(rev, in);
    reverse(rev, rev + size);

    make_table(size);
    printf("%d\n", size + find_match(size));
}

int main() {
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) { solve(); }
    return 0;
}
