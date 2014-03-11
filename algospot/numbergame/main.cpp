#include <iostream>

#define MAX_VALUE 1000000
using namespace std;

const int SIZE = 50;
int n;
int in[SIZE];
int cache[SIZE][SIZE];

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
}

int getMin(int begin, int end) {
    //cout << begin << " " << end << endl;
    if (begin > end) return 0;

    if (cache[begin][end] != -MAX_VALUE) {
        return cache[begin][end];
    }

    int m;
    m = max(in[begin] - getMin(begin+1, end), in[end] - getMin(begin, end-1));
    if (end - begin + 1 >= 2) {
        m = max(m, -getMin(begin+2, end));
        m = max(m, -getMin(begin, end-2));
    } 

    cache[begin][end] = m;
    return m;
}

void solve() {
    int begin = 0;
    int end = n;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cache[i][j] = -MAX_VALUE;
        }
    }
    cout << getMin(0, n-1) << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
