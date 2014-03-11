// http://algospot.com/judge/problem/read/SENTENCE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>


using namespace std;

int m, n;
vector<string> book;
vector<string> memo;

void getInput() {
    cin >> m >> n;
    char buffer [64];
    gets(buffer);
    
    for (int i = 0; i < m; i++) {
        gets(buffer);
        book.push_back(buffer);
    }
    for (int i = 0; i < n; i++) {
        gets(buffer);
        memo.push_back(buffer);
    }

    sort(book.begin(), book.end());
    sort(memo.begin(), memo.end());
}

void solve() {
    int i(0), j(0), count(0);
    while (i < m && j < n) {
        //size_t s = min(book[i].size(), memo[j].size());
        int v = book[i].compare(0, memo[j].size(), memo[j]);
        if (v > 0) j++;
        else if (v < 0) i++;
        else {
            count++;
            //i++;
            j++;
        }
    }

    cout << count << endl;
}

int main() {
    getInput();
    solve();
    return 0;
}
