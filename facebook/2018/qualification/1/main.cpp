// https://www.facebook.com/hackercup/problem/1632703893518337/
// Facebook Hacker Cup 2018 Qualification Round
// Tourist
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

long long n, k, v;
vector<string> in;
map<string, int> indexOf;

void input() {
    cin >> n >> k >> v;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        in.push_back(x);
        indexOf[x] = i;
    }
}

void solve(int no) {
    vector<pair<int, string>> r;
    int start = static_cast<int>((k * (v - 1)) % n);
    for (int i = 0; i < k; i++) {
        const string &s = in[(i+start)%n];
        r.push_back(make_pair(indexOf[s], s));
    }
    sort(r.begin(), r.end());
    cout << "Case #" << no << ": ";
    for (auto &it : r) {
        cout << it.second << " ";
    }
    cout << endl;
}

void clear() {
    in.clear();
    indexOf.clear();
}

int main() {
    int c; cin >> c;
    for (int i = 1; i <= c; i++) {
        input();
        solve(i);
        clear();
    }
    return 0;
}
