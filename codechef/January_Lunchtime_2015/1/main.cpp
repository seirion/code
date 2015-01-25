// http://www.codechef.com/LTIME20/problems/LCH15JAB
// Piece of cake
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int ch[26]; // a ~ z

bool solve() {
    memset(ch, 0, sizeof(int) * 26);

    char buffer[51];
    gets(buffer);
    int i, size = strlen(buffer);
    for (i = 0; i < size; i++) {
        int index = buffer[i] - 'a';
        ch[index]++;
    }
    sort(ch, ch+26, greater<int>());
    int sum = 0;
    for (i = 1; i < 26; i++) {
        sum += ch[i];
    }

    return (ch[0] == sum);
}

int main() {
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
        printf("%s\n", solve() ? "YES" : "NO");
    }
}
