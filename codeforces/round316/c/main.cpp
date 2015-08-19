// codeforces round316
// http://codeforces.com/contest/570/problem/C
#include <iostream>
#include <cstdio>

using namespace std;

int n, query;
char in[300003];
int total(0);

void set_table() {
    bool dot(false);
    int size(n+2), index, num;

    for (int i = 0; i < size; i++) {
        if (dot && in[i] != '.') {
            dot = false;
            total += i - index - 1;
        }
        else if (!dot && in[i] == '.') {
            dot = true;
            index = i;
        }
    }
}

int check(int i, char c) {
    int plus(0);
    if (c == '.' && in[i] != '.') {
        if (in[i-1] == '.') plus++;
        if (in[i+1] == '.') plus++;
    }
    else if (c != '.' && in[i] == '.') {
        if (in[i-1] == '.') plus--;
        if (in[i+1] == '.') plus--;
    }
    return total + plus;
}

int main() {
    scanf("%d %d\n", &n, &query);
    fgets(in+1, sizeof(in)-1, stdin); 
    in[0] = 'x';

    set_table();
    while (query--) {
        int i; char c;
        scanf("%d %c\n", &i, &c);
        total = check(i, c);
        in[i] = c;
        cout << total << "\n";
    }
    return 0;
}
