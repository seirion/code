// https://www.hackerrank.com/contests/w26/challenges/twins
#include <iostream>
#include <vector>

using namespace std;
const int LIMIT = 31623; //sqrt(1e9) == 31622.8

vector<int> prime;

bool is_prime(int p) {
    for (int x : prime) {
        if (p < x * x) break;
        if (p % x == 0) return false;
    }
    return true;
}

void build() {
    prime.push_back(3);
    for (int i = 5; i < LIMIT; i += 2) {
        if (is_prime(i)) prime.push_back(i);
    }
}

int num(int from, int to) { // [from, to]
    if (from <= 3) from = 3;
    else if (from % 2 == 0) from++;
    int r = 0;
    int p = 0;
    while (from <= to) {
        if (is_prime(from)) {
            if (from - p == 2) r++;
            p = from;
        }
        from += 2;
    }
    return r;
}

int main() {
    build();
    int from, to; cin >> from >> to;
    cout << num(from, to) << endl;
    return 0;
}
