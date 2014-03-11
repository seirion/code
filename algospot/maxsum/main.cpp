// http://algospot.com/judge/problem/read/MAXSUM
#include <iostream>

using namespace std;

int n;
int arr[100000];

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void solve() {
    int sum = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum < 0) sum = 0;
        m = max(m, sum);
    }
    cout << m << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
