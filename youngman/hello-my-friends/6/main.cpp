#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <list>

using namespace std;

enum { LEFT, TOP, RIGHT, BOTTOM, NUM };
const int SIZE = 3 * 10000 + 2;

class T {
public:
    bool put(int a, int b) { // [a, b]
        if (v.empty()) {
            v.push_back(make_pair(a, b));
            return true;
        }
        auto next = v.begin();
        while (next != v.end() && next->first <= a) next++;
        //int ka = next->first; int kb = next->second;

        if (next == v.begin()) { // put front
            v.push_front(make_pair(a, b));
        } else {
            auto prev = next;
            prev--;
            int aa = prev->first; int bb = prev->second;
            if (b <= prev->second) return false; // already contains
            if (a <= prev->second + 1) { // concatenation
                prev->second = b;
            } else if (prev->second < a) { // put new one at the end
                v.insert(next, make_pair(a, b));
            }
        }

        // remove next
        while (next != v.end() && next->first <= b+1) {
            auto prev = next;
            prev--;
            prev->second = max(next->second, b);

            prev++;
            next++;
            v.erase(prev);
        }
        return true;
    }

    list<pair<int, int>> v;
    void print() {
        printf("%d\n", v.size());
        for (auto it: v) printf("%d %d    ", it.first, it.second);
        printf("\n");
    }
};

int n;
map<int, int> w, h; // input caching
int in[SIZE][NUM]; // input caching
int in2[SIZE][NUM]; // input caching
T wboard[60002];
T hboard[60002];

inline void counting(map<int, int> &m) {
    int i = 0;
    for (auto &it: m) it.second = i++;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &in[i][LEFT], &in[i][TOP], &in[i][RIGHT], &in[i][BOTTOM]);
        w[in[i][LEFT]] = w[in[i][RIGHT]] = 0;
        h[in[i][TOP]] = h[in[i][BOTTOM]] = 0;
    }
    counting(w);
    counting(h);
    for (int i = 0; i < n; i++) {
        in2[i][LEFT] = w.find(in[i][LEFT])->second;
        in2[i][RIGHT] = w.find(in[i][RIGHT])->second;
        in2[i][TOP] = h.find(in[i][TOP])->second;
        in2[i][BOTTOM] = h.find(in[i][BOTTOM])->second;
    }
}

void solve() {
    vector<bool> result;
    for (int i = n - 1; i >= 0; i--) {
        bool showing = false;
        for (int now = in2[i][TOP]; now <= in2[i][BOTTOM]; now++) {
            if (wboard[now].put(in[i][LEFT], in[i][RIGHT])) showing = true;
        }
        for (int now = in2[i][LEFT]; now <= in2[i][RIGHT]; now++) {
            if (hboard[now].put(in[i][TOP], in[i][BOTTOM])) showing = true;
        }
        result.push_back(showing);
    }
    for (auto it = result.rbegin(); it != result.rend(); it++) {
        if (*it) printf("true\n");
        else printf("false\n");
    }
}

int main() {
    input();
    solve();
    return 0;
}
