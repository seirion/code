// http://algospot.com/judge/problem/read/DOLLS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class VV {
public:
    VV (int i, int v) : index(i), value(v) {}
    int index, value;
    bool operator <(const VV& v) const {return (value < v.value);}
};

int n, m;
int r[100000];
vector<VV> vv;

void getInput() {
    vv.clear();
    cin >> n >> m;
    int doll;
    for (int i = 0; i < n; i++) {
        cin >> doll;
        vv.push_back(VV(i, doll));
    }
    stable_sort(vv.begin(), vv.end());
}

void solve() {
    memset(r, 0, sizeof(int) * n);

    int i, v, acc = 0;
    for (i = 0; i < n; i++) {
        int s = 0; // supplement
        v = vv[i].value;

        if (i) {
            s = (v - vv[i-1].value) * i;
        }

        if(n * v - acc - s >= m) {
            break;
        }
        r[vv[i].index] = v;
        acc += s;
    }

    int base = (i > 0 ? vv[i-1].value : 0);
    int h = ((m - (base * n) + acc) + n - i - 1) / (n - i);
    int k = (n - i) * h - (m - (base * n) + acc);

    for (i = n - 1; i >= 0 && k > 0; i--) {
        if (r[i] == 0) {
            r[i] = base + h - 1;
            k--;
        }
    }
    for (; i >= 0; i--) {
        if (r[i] == 0) {
            r[i] = base + h;
        }
    }

    for (i = 0; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << endl;

}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
