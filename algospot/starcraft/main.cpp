// http://algospot.com/judge/problem/read/STARCRAFT
#include <iostream>
#include <cmath>

using namespace std;

int rate, k;
int combination[20][20] = {0, }; // 1 <= k * 2 - 1 <= 19 

void make_combination() {
    int i;
    for (i = 0; i <= 19; i++) {
        combination[i][0] = 1;
    }
    for (i = 1; i <= 19; i++) {
        for (int j = 1; j <= i; j++) {
            combination[i][j] = combination[i-1][j-1] + combination[i-1][j];
        }
    }
}

void getInput() {
    cin >> rate >> k;
}

void solve() {
    double win = rate / 100.0;
    double lose = 1.0 - win;
    double result = 0.0;
    int all = 2 * k - 1;

    double win_k = pow(win, (double)k);
    double lose_k = 1.0;
    for (int i = k; i <= all; i++) {
        result += win_k * lose_k * combination[i-1][k-1];
        lose_k *= lose;
    }
    cout << (int)((result + 0.005) * 100) << endl;
}

int main() {
    int num;
    cin >> num;
    make_combination();
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
