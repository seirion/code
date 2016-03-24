// http://algospot.com/judge/problem/read/
#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 0xFF;

int n, m;
int price[20], sat[20];
int memo[SIZE] = { 0, }  ; // 0 ~ 200

void calc() {
    memset(memo, 0, sizeof(memo));
    int best = 0;
    for (int i = 1; i <= m; i++) {
        int &now = memo[i & SIZE];
        now = 0; 
        for (int j = 0; j < n; j++) {
            if (0 <= i-price[j]) {
                int temp = memo[(i-price[j]) & SIZE] + sat[j];
                now = max(now, temp);
            }
        }
        best = max(best, now);
    }
    cout << best << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> price[i] >> sat[i];
            price[i] /= 100;
        }
        m /= 100;

        calc();
    }
    return 0;
}
