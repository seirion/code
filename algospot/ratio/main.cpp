// http://algospot.com/judge/problem/read/RATIO
#include <iostream>

using namespace std;

typedef signed long long    int64;

int64 total;
int64 won;

void getInput() {
    cin >> total >> won;
}

void solve() {
    int64 now = won * 100 / total;
    int64 target = 1;

    //binary search
    int64 from = 1, to = 2000000000ll;
    if (((won + to) * 100 / (total + to)) <= now) {
        cout << -1 << endl;
        return;
    }
    // 5 6  5 80
    while (from < to) {
        int64 m = (to + from) / 2;
        int64 r = (won + m) * 100 / (total + m);
        if (r > now) to = m;
        else from = m + 1;
    }

    cout << to << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
