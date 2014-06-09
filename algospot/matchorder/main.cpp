// http://algospot.com/judge/problem/read/MATCHORDER
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int rus[100];
int kor[100];


void getInput() {
    cin >> n;
    int i;
    for (i = 0; i < n; i++) { cin >> rus[i]; }
    for (i = 0; i < n; i++) { cin >> kor[i]; }
    sort(rus, rus+n);
    sort(kor, kor+n);
}

void solve() {
    int count = 0;
    int r(0), k(0);

    while (k < n) {
        if (rus[r] <= kor[k]) {
            r++;
            count++;
        }
        k++;
    }
    cout << count << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
