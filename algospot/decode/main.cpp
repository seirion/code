// http://algospot.com/judge/problem/read/DECODE
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const char *OUT = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
enum {
    RIGHT, DOWN, LEFT, UP,
};

int row, col;
char in[401];
char code[200][201];
bool visit[200][200];


void fill() {
    for (int i = 0; i < row; i++) {
        memcpy(code[i], in + (i*col), sizeof(char) * col);
    }
}

int next(int &r, int &c, int &d) {
    if (d == RIGHT) {
        if (!visit[r][c+1] && c+1 < col) {
            c++;
        }
        else {
            r++;
            d = (d + 1) % 4;
        }
    }
    else if (d == DOWN) {
        if (!visit[r+1][c] && r+1 < row) {
            r++;
        }
        else {
            c--;
            d = (d + 1) % 4;
        }
    }
    else if (d == LEFT) {
        if (!visit[r][c-1] && c-1 >= 0) {
            c--;
        }
        else {
            r--;
            d = (d + 1) % 4;
        }
    }
    else { // d == UP
        if (!visit[r-1][c] && r-1 >= 0) {
            r--;
        }
        else {
            c++;
            d = (d + 1) % 4;
        }
    }
    visit[r][c] = true;
    return code[r][c] - '0';
}

void decode() {
    int i, r(0), c(0), d(0); // row, col, direct
    int limit = strlen(in);

    int co = code[0][0] - '0';
    visit[0][0] = true;
    int count = 2;
    string result;
    for (i = 1; i < limit; i++, count++) {
        co <<= 1;
        co += next(r, c, d);
        if (count % 5 == 0) {
            if (co <= 26)
                result += OUT[co];
            co = 0;
        }
    }
    for (i = result.size() - 1; i >= 0; i--) {
        if (result[i] != ' ') break;
    }
    static int order = 1;
    printf("%d %s\n", order++, result.substr(0, i+1).c_str());
}

void solve() {
    scanf("%d %d ", &row, &col);
    gets(in);
    memset(visit, 0, sizeof(bool) * 200 * 200);
    fill();
    decode();
}

int main() {
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) { solve();}
    return 0;
}
