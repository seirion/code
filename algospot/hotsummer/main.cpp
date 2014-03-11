// http://algospot.com/judge/problem/read/HOTSUMMER
#include <iostream>
#include <algorithm>

using namespace std;

const int size = 9; // 9 ~ 16
int target;
int w[size];

void getInput() {
    cin >> target;
    for (int i = 0; i < size; i++) cin >> w[i];
}

void solve() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += w[i];
    }

    cout << (sum > target ? "NO" : "YES") << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
