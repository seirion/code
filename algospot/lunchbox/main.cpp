// http://algospot.com/judge/problem/read/LUNCHBOX
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Yo {
public :
    Yo(int m, int e) : _m(m), _e(e) {}
    int _m, _e;
    bool operator >(const Yo &yo) const { return _e > yo._e; }
    //bool operator <(const Yo &yo) const { return _e < yo._e; }
};

int n;
int M[10000];
int E[10000];
vector<Yo> v;

void getInput() {
    int in;
    v.clear();
    cin >> n;
    for (int i = 0; i < n; i++) cin >> M[i];
    for (int i = 0; i < n; i++) {
        cin >> E[i];
        v.push_back(Yo(M[i], E[i]));
    }
}

void solve() {
    sort(v.begin(), v.end(), greater<Yo>());
    //for (int i = 0; i < n; i++) cout << v[i]._m << " " << v[i]._e << endl;
    int acc = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
        acc += v[i]._m;
        maxi = max(maxi, acc + v[i]._e);
    }

    cout << maxi << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
