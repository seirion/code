#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int _count;
int _size;
int _on[12];


bool isOk(int index) {
    for (int i = 0; i < index; i++) {
        if (_on[index] == _on[i]) return false;
        if (_on[index] - index == _on[i] - i) return false;
        if (_on[index] + index == _on[i] + i) return false;
    }
    return true;
}

void lay(int index) {
    if (index == _size) {
        _count++;
        return;
    }

    for (int i = 0; i < _size; i++) {
        _on[index] = i;
        if (isOk(index)) {
            lay(index+1);
        }
    }
}

void solve() {
    cin >> _size;

    _count = 0;

    /*
    for (int i = 0; i < _size/2; i++) {
        _on[0] = i;
        lay(1);
    }
    _count = _count << 1;
    if (_size % 2) {
        _on[0] = (_size+1)/2;
        lay(1);
    }
    */
        lay(0);
    cout << _count << endl;
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
