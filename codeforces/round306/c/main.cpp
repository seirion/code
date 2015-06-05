// http://codeforces.com/contest/550/problem/C
// C. Divisibility by Eight
#include <iostream>
#include <string>

using namespace std;

string s;
int n;
int solution;

bool find(int index, int size, int now) {

    if (1 <= size && size <= 3) {
        if (now % 8 == 0) {
            solution = now;
            return true;
        }
    }

    if (now == 0) size = 0;
    if (index == n || size >= 3) return false;

    return find(index+1, size, now) || find(index+1, size+1, now*10 + s[index]-'0');
}

int main() {
    cin >> s;
    if (s == "0") { // 0
        cout << "YES\n0\n";
        return 0;
    }

    n = s.size();
    if (find(0, 0, 0)) {
        cout << "YES\n" << solution << "\n";
    }
    else cout << "NO\n";
    return 0;
}
