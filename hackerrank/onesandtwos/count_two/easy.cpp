// https://www.hackerrank.com/contests/mar14/challenges/ones-and-twos
#include <iostream>
#include <set>


using namespace std;

typedef long long int64;
set <int> solution;


void push_sum(const multiset<int> &ms) {
    int sum = 0;
    multiset<int>::const_iterator i = ms.begin();
    for (; i != ms.end(); i++) { sum += 1 << (*i); }
    solution.insert(sum);
}

void setset(multiset<int> &ms, bool go) {
    push_sum(ms);
    if (ms.size() == 1) {
        return;
    }

    multiset<int> ms2;
    if (go) {
        ms2 = ms;
        int front = *ms2.begin();
        ms2.erase(ms2.begin()); 
        int end = *(--ms2.end());
        ms2.erase(--ms2.end()); 
        ms2.insert(front + end);
        setset(ms2, true);
    }
    int front = *ms.begin();
    ms.erase(ms.begin()); 
    int end = *ms.begin();
    ms.erase(ms.begin()); 
    ms.insert(front + end);
    setset(ms, false);
}

int main() {
    int N, i, j;
    cin >> N;

    for (i = 1; i <= N; i++) {
        multiset<int> ms;
        for (j = 0; j < i; j++) {
            ms.insert(1);
        }
        setset(ms, true);
        cout << solution.size() << endl;
#if 0
        if (true) {
            multiset<int>::const_iterator it = solution.begin();
            for (; it != solution.end(); it++) { cout << *it << "  "; }
            cout << endl;
        }
#endif
    }
    return 0;
}
