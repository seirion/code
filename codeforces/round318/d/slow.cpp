// codeforces round318
// http://codeforces.com/contest/574/problem/D
#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> in;

void solve() {
    int c(0);
    while (!in.empty()) {
        deque<int> temp;
        int size = in.size() - 1;
        for (int i = 1; i < size; i++) {
            if (in[i] == 0) temp.push_back(0);
            else if (in[i] <= in[i-1] && in[i] <= in[i+1]) temp.push_back(in[i] - 1);
            else temp.push_back(min(in[i-1], in[i+1]));
        }
        in.swap(temp);
        while (!in.empty()) {
            if (in.front() != 0) break;
            in.pop_front();
        }
        while (!in.empty()) {
            if (in.back() != 0) break;
            in.pop_back();
        }
        c++;
    }

    cout << c << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        in.push_back(x);
    }
    solve();

    return 0;
}
