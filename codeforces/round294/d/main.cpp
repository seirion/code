// http://codeforces.com/contest/519/problem/D
// D. A and B and Interesting Substrings
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int score[26];
char buffer[100000 + 1];

int main() {
    int i;
    long long sum(0), ans(0);
    for (i = 0; i < 26; i++) {
        scanf("%d", &score[i]);
    }
    scanf("\n");
    gets(buffer);
    int len = strlen(buffer);

    map<pair<char, long long>, int> mm;
    for (i = 0; i < len; i++) {
        sum += score[buffer[i] - 'a'];
        mm[make_pair(buffer[i+1], sum)]++;
    }

    sum = 0;
    for (i = 0; i < len; i++) {
        sum += score[buffer[i] - 'a'];
        ans += mm[make_pair(buffer[i], sum)];
        mm[make_pair(buffer[i+1], sum)]--;
    }

    printf("%I64d\n", ans);
    return 0;
}
