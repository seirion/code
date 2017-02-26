#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class T { public:
    T(int a_ = 0, int b_ = 0) : a(a_), b(b_) {}
    int a, b;
    bool operator<(const T& t) const {
        return (a-b) < (t.a-t.b);
    }
};

int n, k;
T in[200000];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> in[i].a;
    for (int i = 0; i < n; i++) cin >> in[i].b;

    sort(in, in+n);
    
    int i = 0;
    long long r = 0;
    for (; i < k; i++) {
        r += in[i].a;
    }

    for (; i < n; i++) {
        int &a = in[i].a;
        int &b = in[i].b;

        r += min(a, b);
    }

    cout << r << endl;
    return 0;
}

