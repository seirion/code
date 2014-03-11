// http://algospot.com/judge/problem/read/ZEROONE
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int id [1000000];
char buffer [1000000 + 1];

void getInput() {
    fgets(buffer, 1000000 + 1, stdin);

    size_t size = strlen(buffer);
    char c = buffer[0];
    int currentId = 0;
    id[0] = currentId;
    for (int i = 1; i < size; i++) {
        if (buffer[i] != c) {
            c = buffer[i];
            currentId++;
        }
        id[i] = currentId;
    }
}

void solve() {
    int from, to;
    cin >> from >> to;
    cout << (id[from] == id[to] ? "Yes" : "No") << endl;
}

int main() {
    getInput();
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
