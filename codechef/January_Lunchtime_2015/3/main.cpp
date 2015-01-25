// http://www.codechef.com/LTIME20/problems/LCH15JEF
// Just multiply
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int64;

int64 M;
char buffer[10000+1];

int64 power1(int64 base, int64 p) {
    if (p == 0) return 1ll;
    if (p == 1) return base;

    if (p % 2 == 0) {
        int64 temp = power1(base, p/2);
        return temp * temp % M;
    }
    else {
        p--;
        int64 temp = power1(base, p/2);
        return temp * temp * base % M;
    }
}

int64 get(int begin, int end) { // [begin, end)
    int size = strlen(buffer + begin);
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (buffer[begin + i] == '*') {
            index = i + 2;
            break;
        }
    }

    int64 base = atoll(buffer + begin) % M;
    if (index == -1) return base;

    int64 p = atoll(buffer + begin + index) % M;
    return power1(base, p);
}

void solve() {
    scanf("%d ", &M);
    gets(buffer);
    vector<int64> s;

    int i, size = strlen(buffer);
    int begin = 0;
    for (i = 0; i < size; i++) {
        if (buffer[i] == '*') {
            if (buffer[i+1] == '*') {
                i++;
            }
            else {
                buffer[i] = '\0';
                s.push_back(get(begin, i));
                begin = i + 1;
            }
        }
    }
    s.push_back(get(begin, i));

    int64 r = 1;
    vector<int64>::iterator it = s.begin();
    for (; it != s.end(); it++) {
        r = r * (*it) % M;
    }
    printf("%lld\n", r);
}

int main() {
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
}
