// http://algospot.com/judge/problem/read/PREFIX
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int N, M;
string in[3000];
map<string, int> counter[200];

void getInput() {
    cin >> N >> M;
    cin.get();
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
}

void solve() {
    int i;
    for (i = 0; i < N; i++) {
        size_t s = in[i].size();
        for (int j = 0; j < s; j++) {
            counter[j][in[i].substr(0, j+1)]++;
        }
    }

    map<string, int>::const_iterator it, maxi;
    for (i = 0; i < M; i++) {
        it = counter[i].begin();
        maxi = counter[i].begin();
        for (; it != counter[i].end(); it++) {
            if (maxi->second < it->second) {
                maxi = it;
            }
        }
        cout << maxi->first << endl;
    }
}

void clear() {
    for (int i = 0; i < M; i++) { 
        counter[i].clear();
    }
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve(); clear();}
    return 0;
}
