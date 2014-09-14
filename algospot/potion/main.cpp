// http://algospot.com/judge/problem/read/POTION
#include <cstdio>
#include <set>

using namespace std;

int n;
int potion[200];
int current[200];

void swap(int &a, int &b) {
    a ^= b; b ^= a; a ^= b;
}

int _gcd(int a, int b) { // a < b
    while (true) {
        b = b % a;
        if (b == 0) return a;
        swap(a, b);
    }
}

void solve() {
    int i;
    scanf("%d", &n);
    set<int> s;
    for (i = 0; i < n; i++) {
        scanf("%d", &potion[i]);
        s.insert(potion[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &current[i]);
    }

    set<int>::const_iterator it = s.begin();
    int gcd = *it;
    it++;
    for (;it != s.end(); it++) {
        if (gcd == 1) break;
        gcd = _gcd(gcd, *it);
    }

    int ratio = 0;
    i = 0;
    for (; i < n; i++) {
        int v = potion[i] + (potion[i] / gcd * ratio);
        if (v < current[i]) {
            ratio += (current[i] - v + (potion[i] / gcd) - 1) / (potion[i] / gcd);
        }
    }


    for (i = 0; i < n; i++) {
        printf("%d ", potion[i] + (potion[i] / gcd * ratio) - current[i]);
    }
    printf("\n");
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
