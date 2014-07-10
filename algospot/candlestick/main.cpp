// http://algospot.com/judge/problem/read/CANDLESTICK
#include <iostream>

using namespace std;

int n;
int in[];

void getInput() {
    cin >> n;
    int from, to;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
    }
}

void solve() {
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
