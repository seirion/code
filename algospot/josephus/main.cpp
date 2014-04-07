// http://algospot.com/judge/problem/read/JOSEPHUS
#include <iostream>
#include <list>

using namespace std;

int n, k;


void getInput() {
    cin >> n >> k;
}

void solve() {
    list<int> _list;
    for (int i = 0; i < n; i++) {
        _list.push_back(i);
    }

    k--;
    int current = 0;
    while (_list.size() > 2) {
        list<int>::iterator it = _list.begin();
        advance(it, current);
        _list.erase(it); 
        current += k;
        current = current % _list.size();
    }

    list<int>::const_iterator iter = _list.begin();
    cout << *iter + 1 << " ";
    iter++;
    cout << *iter + 1 << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
