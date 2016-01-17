// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-16-closest-numbers
// Day 16: Sorting!

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int in[200000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    sort(in, in+n);

    vector<pair<int, int>> v;
    v.push_back(make_pair(in[0], in[1]));
    int min_diff = in[1] - in[0];

    for (int i = 1; i < n; i++) {
        int diff = in[i] - in[i-1];
        if (min_diff == diff) {
            v.push_back(make_pair(in[i-1], in[i]));
        }
        else if (diff < min_diff) {
            v.clear(); 
            min_diff = diff;
            v.push_back(make_pair(in[i-1], in[i]));
        }
    }

    for (auto x : v) {
        printf("%d %d ", x.first, x.second);
    }
    printf("\n");
    return 0;
}
