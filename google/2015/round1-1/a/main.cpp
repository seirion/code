// https://code.google.com/codejam/contest/4224486/dashboard#s=p0
// Problem A. Mushroom Monster

#include <cstdio>
#include <iostream>

using namespace std;

int n, in[10001];
int have_to_eat;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
}

void way_1() {
    int eat = 0;
    have_to_eat = 0;
    for (int i = 1; i < n; i++) {
        if (in[i-1] > in[i]) eat += (in[i-1] - in[i]);
        have_to_eat = max(have_to_eat, in[i-1] - in[i]);
    }
    cout << eat << " ";
}

void way_2() {
    n--;
    int now = in[0];
    int eat = 0;
    for (int i = 0; i < n; i++) {
        eat += min(have_to_eat, in[i]);
    }
    cout << eat << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        cout << "Case #" << i << ": ";
        way_1();
        way_2();
    }
}

