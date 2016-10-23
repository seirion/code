#include <iostream>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

struct T {
    T(long long n_ = 0, long long w_ = 0): n(n_), w(w_) {}
    long long n, w;
    bool operator >(const T& x) const { return n > x.n; }
    long long diff() const { return w - n; }
};

struct comp {
    bool operator() (const T& a, const T&b) { return a.diff() < b.diff(); }
};

bool sort_by_weight(const T& a, const T&b) { return a.diff() < b.diff(); }

int n;
T me;
//T in[300000];

multiset<T, comp> upper;
multiset<T, greater<T>> lower;


int main() {
    cin >> n;
    cin >> me.n >> me.w;

    T in;
    for (int i = 1; i < n; i++) {
        cin >> in.n >> in.w;
        if (in > me) upper.insert(in);
        else lower.insert(in);
    }

    //for (auto x : upper) cout << x.n << " " << x.w << endl; cout << "----\n";
    //for (auto x : lower) cout << x.n << " " << x.w << endl; cout << "----\n";
    int best = upper.size();

    while (!upper.empty()) {
        if (me.n <= upper.begin()->diff()) break;

        me.n -= upper.begin()->diff() + 1;
        upper.erase(upper.begin());

        while (!lower.empty() && me.n < lower.begin()->n) {
            upper.insert(*lower.begin());
            lower.erase(lower.begin());
        }

        best = min(best, (int) upper.size());
    }

    best = min(best, (int) upper.size());
    cout << best+1 << endl;
    return 0;
}
