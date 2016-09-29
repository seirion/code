//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> in[100];

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int from, to, index; cin >> from >> to >> index;
        in[index].push_back(make_pair(from, to));
    }
}

void merge(vector<pair<int, int>> &v) {
    sort(v.begin(), v.end());
    vector<pair<int, int>> vv;

    pair<int, int> prev = make_pair(-2, -1);
    for (auto &p : v) {
        if (p.second <= prev.second) continue;

        if (prev.second < p.first) vv.push_back(p);
        else {
            vv.back().second = p.second;
        }
        prev = vv.back();
    }

    v.swap(vv);
}

void intersect(vector<pair<int, int>> &now, vector<pair<int, int>> &v) {
    int size1(now.size()), size2(v.size());
    int i(0), j(0); 

    vector<pair<int, int>> temp;
    while (i < size1 && j < size2) {
        if (now[i].second < v[j].first) { i++; continue; }
        if (v[j].second < now[i].first) { j++; continue; }

        auto p = make_pair(max(now[i].first, v[j].first),
                           min(now[i].second, v[j].second));
        temp.push_back(p);
        if (now[i].second == v[j].second) { i++; j++; }
        else if (now[i].second < v[j].second) i++;
        else j++;
    }

    now.swap(temp);
}

void solve() {
    for (int i = 1; i <= k; i++) merge(in[i]);

    vector<pair<int, int>> now = in[1];
    for (int i = 2; i <= k; i++) intersect(now, in[i]);

    int best = 0;
    pair<int, int> segment;

    for (auto p : now) {
        if (best < p.second - p.first + 1) {
            best = p.second - p.first + 1;
            segment = p;
        }
    }

    if (best == 0) {
        cout << -1<< endl;
    }
    else {
        cout << segment.first << " " << segment.second << endl;
    }
}

void clear() {
    for (int i = 1; i <= k; i++) in[i].clear();
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); clear(); }
    return 0;
}
