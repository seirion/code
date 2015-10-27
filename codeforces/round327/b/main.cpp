// http://codeforces.com/contest/591/problem/B
#include <cstdio>
#include <map>

using namespace std;

int n, m;
char in[200002];
int order[26];

void swap_char(int a, int b) {
    for (int i = 0; i < 26; i++) {
        if (order[i] == a) {
            order[i] = b;
        }
        else if (order[i] == b) {
            order[i] = a;
        }
    }
}

void arrange() {
    for (int i = 0; i < 26; i++) {
        order[i] = i;
    }

    for (int i = 0; i < m; i++) {
        char a, b;
        scanf("%c %c\n", &a, &b);
        swap_char(a-'a', b-'a');
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        printf("%c", order[in[i]-'a'] + 'a');
    }
    printf("\n");
}

int main() {
    scanf("%d %d\n", &n, &m);
    fgets(in, 200002, stdin);
    arrange();
    print();
    return 0;
}
