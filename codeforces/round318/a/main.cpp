// codeforces round318
// http://codeforces.com/contest/574/problem/A
#include <iostream>
#include <queue>

using namespace std;

int n, me;
int in[100];

int main() {
    cin >> n;
    cin >> me;
    priority_queue<int> Q;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        Q.push(x);
    }

    int candy(0);
    while (me <= Q.top()) {
        int t = Q.top(); Q.pop();
        if (me > t) break;
        me++; candy++; t--;
        Q.push(t);
    }

    cout << candy << endl;
    return 0;
}
