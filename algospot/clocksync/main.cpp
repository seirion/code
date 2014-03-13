// http://algospot.com/judge/problem/read/CLOCKSYNC
#include <iostream>

using namespace std;

int sw [] = { // switch
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

int s [16];
int n;


void getInput() {
   for (int i = 0; i < 16; i++) {
       cin >> s[i];
   } 
}

bool check(int num) {
    for (int i = 0; i < 10; i++) {
        int r = sw[i];
        while (r) {
            __builtin_ctz(r);
            r &= r - 1;
        }
        cout << endl;
    }
}

void solve() {
    int flags [16] = {0, };
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
