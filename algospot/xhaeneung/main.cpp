// http://algospot.com/judge/problem/read/XHAENEUNG
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const char *FIGURE[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"
};

int n;
char buffer [40];

void getInput() {
    cin.getline(buffer, 40);
}

int findIndex(char *c) {
    int i = 0;
    for (; i < 11; i++) {
        if (strcmp(FIGURE[i], c) == 0) break;
    }
    return i;
}

int cal(int l, int r, char op) {
    switch (op) {
        case '+' : return l + r;
        case '-' : return l - r;
        case '*' : return l * r;
        default : return 0;
    }
}

void solve() {
    char *left = &buffer[0];
    int index = strchr(left, ' ') - left;
    buffer[index] = '\0';
    char op = buffer[index+1];
    char *right = &buffer[index+3];

    index = strchr(right, ' ') - right;
    right[index] = '\0';

    char *answer = &right[index+3];

    //
    int l = findIndex(left);
    int r = findIndex(right);
    int result = cal(l, r, op);
    if (result >= 0 && result <= 10) {
        char target[11];
        strcpy(target, FIGURE[result]);
        sort(target, target + strlen(target));
        sort(answer, answer + strlen(answer));
        if (strcmp(target, answer) == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int num;
    cin >> num;
    cin.getline(buffer, 40);
    for (int i = 0; i < num; i++) {
        getInput();
        solve();
    }
    return 0;
}
