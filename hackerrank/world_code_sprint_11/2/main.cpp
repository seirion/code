#include <iostream>
#include <string>
#include <vector>

using namespace std;

int len, m, b;
vector<int> mul;
string s;

void build() {
    mul.resize(len);
    mul[0] = 1;
    for (int i = 1; i < len; i++) {
        mul[i] = mul[i-1] * b % m;
    }
}

int main() {
    cin >> s >> len >> b >> m;
    build();

    int i;
    int now = 0;
    for (i = 0; i < len; i++) {
        now += (s[i]-'0') * mul[len-i-1];
        now = now % m;
    }

    int result = now;
    int j = 0;
    for (; i < s.size(); i++, j++) {
        now -= (s[j]-'0') * mul[len-1];
        now = (now * b + (s[i]-'0')) % m;
        if (now < 0) now += m;
        result += now;
    }

    cout << result << endl;
    return 0;
}
