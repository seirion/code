// http://algospot.com/judge/problem/read/STRJOIN
#include <iostream>
#include <list>

using namespace std;

list<int> s;

void getInput() {
    int n;
    cin >> n;
    int in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        s.push_back(in);
    }
}

void solve() {
    s.sort();
    int sum = 0;
    int a, b;

    while (!s.empty()) {
        a = s.front();
        s.pop_front();

        if (s.empty()) break; //
        b = s.front();
        s.pop_front();

        sum += a + b;

        list<int>::iterator it = s.begin();
        for (; it != s.end(); it++) {
            if (*it > a + b) {
                break;
            }
        }
        s.insert(it, a+b);
    }

    cout << sum << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
