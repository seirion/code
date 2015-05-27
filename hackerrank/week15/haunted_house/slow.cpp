// https://www.hackerrank.com/contests/w15/challenges/haunted-house
// Weekly Challenges - Week 15 Haunted House
#include <cstdio>
#include <map>

using namespace std;

int mm[300002] = {0, };

int main() {
    int n, low, high;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &low, &high);
        for (int i = low+1; i <= high+1; i++) {
            mm[i]++;
        }
    }

    for (int i = 300001; ;i--) {
        if (i <= mm[i]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
