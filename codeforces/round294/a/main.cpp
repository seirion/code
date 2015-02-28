// http://codeforces.com/contest/519/problem/A
// A. A and B and Chess
#include <cstdio>

int score [256];

using namespace std;

int main() {
    score['Q'] = 9;
    score['R'] = 5;
    score['B'] = 3;
    score['N'] = 3;
    score['P'] = 1;
    score['K'] = 0;

    score['q'] = -9;
    score['r'] = -5;
    score['b'] = -3;
    score['n'] = -3;
    score['p'] = -1;
    score['k'] = 0;
    score['.'] = 0;

    char buffer[10];
    int sum(0);
    for (int i = 0; i < 8; i++) {
        gets(buffer);
        for (int j = 0; j < 8; j++) {
            sum += score[buffer[j]];
        }
    }

    if (sum == 0) printf("Draw\n");
    else if (sum > 0) printf("White\n");
    else printf("Black\n");
    return 0;
}
