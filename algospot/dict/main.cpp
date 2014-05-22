// http://algospot.com/judge/problem/read/DICT
#include <iostream>
//#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long       int64;


int64 comb[101]; // comb[i] : combination(b + i, i)
char result[201];

void set_combination_table(int until, int base) {
    memset(comb, 0, sizeof(int64) * 101);

    comb[0] = 1;
    comb[1] = base + 1;
    for (int i = 2; i <= until; i++) {
        comb[i] = comb[i-1] * (base+i) / i;
    }
}

void print_string(int a, int b, int n) {
}


void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    if (a == 0 && b == 0) {
        cout << "NONE" << endl;
        return;
    }
    if (a == 0 || b == 0) {
        if (n > 1) {
            cout << "NONE" << endl;
            return;
        }
        else {
            memset(result, 'a', a);
            memset(result + a, 'b', b);
            result[a+b] = '\0';
            cout << result << endl;
            return;
        }
    }

    set_combination_table(a, b); // ex: a=6, b=4 ==> 000000 1111

    print_string(a, b, n);
    // test
    for (int i = 0; i < a; i++) {
        cout << comb[i] << endl;
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
