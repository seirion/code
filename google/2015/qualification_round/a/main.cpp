#include <iostream>
#include <string>

using namespace std;

int n;
string str;

void input() {
    cin >> n >> str;
}

void solve(int cases) {
    int now = str[0] - '0';
    int need = 0;
    for (int i = 1; i <= n; i++) {
        int current = str[i] - '0';
        if (current == 0) continue;

        if (now < i) {
            need += (i - now);
            now = i;
        }
        now += current;
    }

    cout << "Case #" << cases << ": " << need << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }
}
