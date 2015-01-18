// http://codeforces.com/contest/505/problem/A
// Problem A
#include <cstdio>
#include <cstring>

using namespace std;

bool possible(char *in, int size, int at) {
    int i(0), j(0);
    char temp[32] = {0,};

    for (; i <= size; i++) {
        if (i != at) temp[i] = in[j++];
        else temp[i] = '*';
    }

    i = 0; j = size;
    while (i < j) {
        if (temp[i] == '*') temp[i] = temp[j];
        else if (temp[j] == '*') temp[j] = temp[i];
        if (temp[i] != temp[j]) return false;
        i++; j--;
    }

    printf("%s\n", temp);
    return true;
}

int main() {
    char in[16];
    gets(in);
    int size = strlen(in);

    for (int i = 0; i <= size; i++) {
        if (possible(in, size, i)) return 0;
    }
    printf("NA\n");
    return 0;
}
