// https://www.hackerrank.com/contests/w15/challenges/haunted-house
// Weekly Challenges - Week 15 Haunted House
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

vector<pair<int, int> > vv;

int main() {
    int n, low, high;

    scanf("%d", &n);
    vv.reserve(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &low, &high);
        vv.push_back(make_pair(high+1, low+1));
    }
    sort(vv.begin(), vv.end(), greater<pair<int, int>>());
    //vv.push_back(make_pair(0, 0));

    int now(0x7FFFFFFF), size(vv.size());
    priority_queue<int> Q;

    for (int i = 0; i < size; i++) {
        if (now <= Q.size()) {
            printf("%d\n", now);
            return 0;
        }

        now = vv[i].first;
        if (!Q.empty() && now < Q.size() && Q.size() >= Q.top()) {
            printf("%d\n", Q.size());
            return 0;
        }
        while (!Q.empty()) {
            if (now < Q.top()) {
                Q.pop();
            }
            else break;
        }
        Q.push(vv[i].second);
    }

    printf("%d\n", min(now, (int)Q.size()));
    return 0;
}
