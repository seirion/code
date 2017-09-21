#include <iostream>
#include <string>

using namespace std;

string a, b, abba;

char find(long long gen, long long pos, long long len) {
    //cout << "gen: " << gen << "  pos: " << pos << "  len: " << len << endl;
    if (gen == 1) {
        if (abba.size() <= pos) return 'X';
        else return abba[pos];
    }

    long long q = len / 4;
    int r = 0;
    if (pos < q) {
    } else if (pos < q*2) {
        pos -= q;
        r = 1;
    } else if (pos < q*3) {
        pos -= q*2;
        r = 1;
    } else {
        pos -= q*3;
    }
    return find(gen-1, pos*2+r, len/2);
}

void solve() {
    long long an, bn, gen, ss, pos, len;
    cin >> an >> bn >> gen >> ss >> pos >> a >> b;

    len = an + bn;
    for (int i = 1; i <= gen; i++) len <<= 1;

    abba = a + b + b + a;
    //cout << abba.size() << "  :::  " << abba << endl;
    cout << find(gen, (pos-1)*2+ss, len) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

