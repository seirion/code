// https://www.hackerrank.com/contests/w15/challenges/haunted-house
// Weekly Challenges - Week 15 Haunted House
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

pair<int, int> pp[6000000]; // index, (in/out)

int main() {
    int n, low, high;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &low, &high);
        pp[i*2] = make_pair(high+1, 1/*in*/);
        pp[i*2+1] = make_pair(low, -1/*out*/);
    }
    n = n << 1;
    sort(pp, pp + n, greater<pair<int, int> >());


    int num = 0, now;
    for (int i = 0; i < n; ) {
        now = pp[i].first;
        if (num > now) {
            break;
        }

        while (now == pp[i].first) {
            num += pp[i++].second;
        }

        if (num >= now) {
            num = now;
            break;
        }
    }
    printf("%d\n", num);
    return 0;
}
