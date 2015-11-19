// https://algospot.com/judge/problem/read/CHILDRENDAY
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> num;

void input() {
    string s;
    cin >> s >> n >> m;
    num.clear();
    for (char c : s) {
        num.push_back(c-'0');
    }
    sort(num.begin(), num.end());
}

void solve() {
    queue<long long> Q;
    Q.push(0);

    while (!Q.empty()) {
        long long now = Q.front(); Q.pop();
        if ((now - m) > 0 && (now - m) % n == 0) {
            cout << now << endl;
            return;
        }
        for (int x : num) {
            if (now > 0 || x > 0) Q.push(now*10 + x);
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve();}
    return 0;
}
