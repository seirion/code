// http://algospot.com/judge/problem/read/CLOCKSYNC
#include <iostream>
#include <cstdio>

using namespace std;

unsigned int sw [] = { // switch
    7,      //    {0, 1, 2},
    2696,   //    {3, 7, 9, 11},
    50192,  //    {4, 10, 14, 15},
    241,    //    {0, 4, 5, 6, 7},
    5568,   //    {6, 7, 8, 10, 12},
    49157,  //    {0, 2, 14, 15},
    49160,  //    {3, 14, 15},
    49328,  //    {4, 5, 7, 14, 15},
    62,     //    {1, 2, 3, 4, 5},
    8760    //    {3, 4, 5, 9, 13}
};

unsigned int state;
int n;
int count;

void getInput() {
    int in;
    state = 0;
    for (int i = 0; i < 16; i++) {
        cin >> in;
        in = (in / 3) % 4;
        state |= (in & 0x3) << (i * 2);
    }
}

unsigned int move(int index, unsigned int st) {
    unsigned int r = sw[index];
    while (r) {
        unsigned int i = __builtin_ctz(r) * 2;

        unsigned int current = (st & (3 << i)) + (1 << i);
        st &= ~(0x3 << i);
        st |= current & (3 << i);

        r &= r - 1;
    }
    return st;
}


void test(int c, int index, unsigned int st) {
    if (c >= count) return;
    if (st == 0) {
        count = c;
        return;
    }
    if (index == 10) return;

    for (int i = 0; i < 4; i++) {
        test(c + i, index + 1, st);
        st = move(index, st);
    }
}


void solve() {
    count = 500;
    unsigned int st = state;
    for (int i = 0; i < 4; i++) {
        test(i, 1, st);
        st = move(0, st);
    }

    if (count == 500) count = -1;
    cout << count << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
