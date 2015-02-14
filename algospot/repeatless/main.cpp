// http://algospot.com/judge/problem/read/REPEATLESS
#include <cstdio>
#include <cstring>
#include <list>
#include <vector>

using namespace std;

int num_of_digit[] = {
    1, 9, 9*9, 9*9*8, 9*9*8*7, 9*9*8*7*6, 9*9*8*7*6*5, 9*9*8*7*6*5*4, 9*9*8*7*6*5*4*3
};

void solve(int n) {
    int digit = 1;
    int i, prev(0), current(0);
    while (true) {
        current += num_of_digit[digit];
        if (current >= n) break;
        prev = current; 
        digit++;
    }
    n -= prev;


    list<int> ll;
    for (i = 0; i <= 9; i++) ll.push_back(i);

    list<int>::iterator it = ll.begin(); it++; // start from 1
    vector<int> solution;
    int divider = 9;
    current = num_of_digit[digit] / divider;
    for (;;) {
        if (current > n) {
            solution.push_back(*it);
            ll.erase(it);
            current = current / divider--;
            it = ll.begin();
        }
        else {
            n -= current;
            if (n == 0) break;
            it++;
        }
    }
    solution.push_back(*it);
    ll.erase(it);

    for (i = solution.size(); i < digit; i++) {
        solution.push_back(ll.back());
        ll.pop_back();
    }

    for (i = 0; i < solution.size(); i++) printf("%d", solution[i]);
    printf("\n");
}

int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        solve(n);
    }
    return 0;
}
