// Problem4
// hyungyu.jang@lge.com

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <code/debug.h>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


///////////////////////////////////////////////////////////////////////
int w, n; // width, num
char buffer[100][100];
vector< string > in;
vector<int> size;
int start[40] = {0,};

void getInput() {
    scanf("%d %d\n", &w, &n);
    char buffer[101];
    for (int i = 0; i < n; i++) {
#ifdef __linux__
        in.push_back(string());
        getline(std::cin, in[i], '\n');
#else
        gets(buffer);
        in.push_back(string(buffer));
#endif
    }

    std::sort(in.begin(), in.end());
}


int getMaxWidth(int from, int col) {
    int maxi = size[from];
    int to = min(n, from + col);
    for (int i = from + 1; i < to; i++) {
        maxi = max(maxi, size[i]);
    }
    return maxi;
}

void solve() {
    int i;
    for (i = 0; i < n; i++) {
        size.push_back(in[i].size());
    }

    int s = size[0];
    int num = 1;
    for (i = 1; i < n; i++) {
        s += 2 + size[i];
        if (s > w) break;
        num++;
    }

    int col;
    for (i = num; i > 0; i--) { // num : word in a line
        s = 0;
        col = (n + i - 1) / i;
        int from = 0;
        for (int j = 0; j < i; j++) { // j : column
            int v = getMaxWidth(from , col) + 2;
            start[j+1] = start[j] + v;
            s += v;
            from += col;
        }
        s -= 2; // the last
        if (s <= w) {
            num = i;
            break;
        }
    }

    char screen[101];

    for (i = 0; i < col; i++) {
        memset(screen, '_', 100);
        screen[w] = '\0';
        int position = i;
        for (int j = 0; j < num && position < n; j++) {
            strncpy(screen + start[j], in[position].c_str(), size[position]);
            position += col;
        }
        trace("%s\n", screen);
    }
}

int main(int argc, char *argv[]) {
    getInput();
    solve();
    return 0;
}
