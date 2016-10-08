#include <iostream>
#include <set>
#include <map>

using namespace std;


int n;
long long in[100001];
multiset<long long> s;
map<int, int> m;

void del(int x) {
    auto it = m.lower_bound(x);
    if (it == m.end() || x < it->first) it--;

    // a <= x <= b
    int a = it->first;
    int b = it->second;
    m.erase(it);

    long long sum = in[b] - in[a-1];
    auto ii = s.find(sum);
    s.erase(ii);

    if (x != b) {
        s.insert(in[b] - in[x]);
        m[x+1] = b;
    }
    if (x != a) {
        s.insert(in[x-1] - in[a-1]);
        m[a] = x - 1;
    }
}

int main() {
    cin >> n;
    long long sum = 0;
    in[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        in[i] += in[i-1];
    }

    s.insert(in[n]); // total
    m[1] = n; // [1, n]

    while (n--) {
        int x; cin >> x;
        del(x);
        if (!s.empty()) {
            cout << *s.rbegin() << endl;
        }
        else cout << "0\n";
    }
    return 0;
}
