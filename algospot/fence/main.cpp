// http://algospot.com/judge/problem/read/FENCE
#include <iostream>

using namespace std;

int n;
int in[20000];


void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
}

void solve() {
    int maxi = 0;
    
    for (int from = 0; from < n; from++) {
        int mini = in[from];
        for (int to = from; to < n; to++) {
            mini = min(mini, in[to]);
            maxi = max(maxi, (to - from + 1) * mini); 
            if (maxi >= (n - from) * mini) break;
        }
    }

    cout << maxi << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
