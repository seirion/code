// http://algospot.com/judge/problem/read/PI
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n;
char in[10002];
int memo[10002]; // momo-ization

void getInput() {
    gets(in+1);
}


int cal(int from, int to) {
    if (to - from < 2) return 10; // === if (to - from + 1 < 3)

    bool check = true;
    for (int i = from + 1; i <= to; i++) { // condition 1
        if (in[from] != in[i]) {
            check = false;
            break;
        }
    }
    if (check) return 1;

    check = abs(in[from+1] - in[from]) == 1;
    if (check) {
        int jump = in[from+1] - in[from];
        for (int i = from + 2; i <= to; i++) { // condition 2
            if (in[i] - in[i-1] != jump) {
                check = false;
                break;
            }
        }
    }
    if (check) return 2;

    check = in[from] == in[from + 2];
    if (check) {
        for (int i = from + 4; i <= to; i += 2) { // condition 3
            if (in[from] != in[i]) {
                check = false;
                break;
            }
        }
    }
    if (check) {
        for (int i = from + 3; i <= to; i += 2) { // condition 3
            if (in[i] != in[i-2]) {
                check = false;
                break;
            }
        }
    }
    if (check) return 4;

    int jump = in[from+1] - in[from];
    check = true;
    for (int i = from + 2; i <= to; i++) { // condition 4
        if (in[i] - in[i-1] != jump) {
            check = false;
            break;
        }
    }
    if (check) return 5;
    return 10;
}

void solve() {
    size_t size = strlen(in);

    memo[0] = memo[1] = memo[2] = 10;
    memo[3] = cal(1, 3);
    memo[4] = cal(1, 4);
    memo[5] = cal(1, 5);
    for (int i = 6; i < size; i++) {
        memo[i] = min(memo[i - 3] + cal(i - 2, i), memo[i - 4] + cal(i - 3, i));
        memo[i] = min(memo[i], memo[i - 5] + cal(i - 4, i));
    }

    cout << memo[size - 1] << endl;
}

int main() {
    in[0] = '0';
    int num;
    cin >> num;
    cin.get();
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
