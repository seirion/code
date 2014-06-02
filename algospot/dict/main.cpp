// http://algospot.com/judge/problem/read/DICT
#include <iostream>
#include <cstring>

using namespace std;

typedef long long int64;

int position;
char result[201];


void print_string(int a, int b, int n) {
    if (a == 0 || b == 0) {
        if (n > 1) {
            cout << "NONE" << endl;
            return;
        }
        else {
            memset(result + position + a, 'b', b);
            cout << result << endl;
            return;
        }
    }
    if (n == 1) {
        memset(result + position + a, 'b', b);
        cout << result << endl;
        return;
    }

    int64 i, before(1), current(1);
    for (i = 1; i < a; i++) {
        current = current * (b+i) / i;
        if (n <= current) break;
        before = current;
    }

    position += a - i;
    result[position++] = 'b';
    print_string(i, b-1, n-before);
}


void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    memset(result, 'a', 200);
    position = 0;
    result[a+b] = '\0';

    if (a == 0 && b == 0) {
        cout << "NONE" << endl;
        return;
    }
    print_string(a, b, n);
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
