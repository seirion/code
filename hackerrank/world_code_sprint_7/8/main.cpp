// https://www.hackerrank.com/contests/world-codesprint-7/challenges/sock-merchant
// Sock Merchant 
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct P {
    P(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    int x, y;
};

P operator -(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
bool is_left(const P& a, const P& b) { return 0 < a.x*b.y - a.y*b.x; } // cross product
double distance(const P &a, const P &b) { return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); }


int n, a, b;
P in[500];

double ab(int aaa, int bbb) { // a -> b
    vector<P> out;
    out.push_back(in[aaa]);

    for (int i = aaa + 1; true; ) {
        P &xx = in[i % n];

        if (out.size() == 1) {
            out.push_back(xx);

            if ((i % n) == bbb) break;
            i++;
            continue;
        }

        P aa(out[out.size()-2]), bb(out[out.size()-1]);

        if (is_left(bb - aa, xx - aa)) {
            out.push_back(xx);
            if ((i % n) == bbb) break;
            i++;
        }
        else {
            if (1 < out.size()) out.pop_back();
        }

    }

#if 0
    for (auto xx : out) {
        cout << xx.x << " " << xx.y << endl;
    }
    cout << endl;
#endif
    double r = 0.0;
    for (int i = 1; i < out.size(); i++) {
        r += distance(out[i-1], out[i]);
    }

    //printf ("                %0.7f\n", r);
    return r;
}

bool is_ccw() {
    double r = 0.0;

    int i = 0;

    return true;
}

int main() {
    cin >> n >> a >> b;
    a--; b--; // 0-based
    for (int i = 0; i < n; i++) {
        cin >> in[i].x >> in[i].y;
    }

    if (!is_ccw()) { // need to reverse
    }
    printf ("%0.7f\n", max(ab(a, b), ab(b, a)));
    return 0;
}
