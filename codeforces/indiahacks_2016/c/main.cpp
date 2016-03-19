#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n;
int in[150002];
vector<int> v;

void swap(int a, int b) {
    int temp = in[a];
    in[a] = in[b];
    in[b] = temp;
}

bool ok(int x) {
    if (x <= 0 || n <= x) return true;

    if (x&1) { // ODD
        if (in[x] >= in[x+1]) return false;
    }
    else {
        if (in[x] <= in[x+1]) return false;
    }
    return true;
}

bool check() {

    for (int x : v) {
        if (x <= 0 || n <= x) continue;
        if (x&1) { // ODD
            if (in[x] >= in[x+1]) return false;
        }
        else {
            if (in[x] <= in[x+1]) return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in[i];

    set<int> fix;
    for (int i = 1; i < n; i++) {
        if (i&1) { // ODD
            if (in[i] >= in[i+1]) {
                if (1 < i) fix.insert(i-1);
                fix.insert(i);
                fix.insert(i+1);
            }
        }
        else {
            if (in[i] <= in[i+1]) {
                fix.insert(i-1);
                fix.insert(i);
                fix.insert(i+1);
            }
        }
    }

    if (20 <= fix.size()) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> temp(fix.begin(), fix.end());
    v.swap(temp);

    set<pair<int, int>> result;
    for (int x : v) { // x : index
        for (int i = 1; i <= n; i++) {
            if (i == x) continue;
            swap(x, i);
            if (ok(i-1) && ok(i) && ok(i+1) && check()) {
                result.insert(make_pair(min(x,i), max(x,i)));
            }
            swap(x, i);
        }

    }
    cout << result.size() << endl;
    return 0;
}
