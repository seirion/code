// http://algospot.com/judge/problem/read/PALINDROMIZE
#include <cstdio>
#include <cstring>

using namespace std;

char in[100 * 1000 + 1];

bool palindrome(char *str, int size) {
    int low(0), high(size-1);
    while (low < high) {
        if (str[low] != str[high]) return false;
        low++; high--;
    }
    return true;
}

void solve() {
    gets(in);
    int i, size = strlen(in);

    for (i = 0; i < size; i++) {
        if (palindrome(in+i, size-i)) break;
    }
    printf("%d\n", size+i);
}

int main() {
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) { solve(); }
    return 0;
}
