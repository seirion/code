#include <iostream>
#include <set>

using namespace std;

int main() {
    int n; cin >> n;
    set<int> v;

    while (n--) {
        int x; 
        cin >> x;
        v.insert(x);
    }
    int prev = -100;
    int ccc = 0;
    for (int x : v) {
        if (prev + 1 == x) ccc++;
        else ccc = 1;
        prev = x;
        if (ccc == 3) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
