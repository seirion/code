// http://algospot.com/judge/problem/read/BRAVEDUCK
#include <iostream>
#include <deque>
#include <list>

#define BASE 2000
using namespace std;


int j, n;
int target;
deque<int> used;
list<int> remain;

int getX(int v) {
    return ((v >> 16) & 0x0000FFFF);
}
int getY(int v) {
    return ((v & 0x0000FFFF));
}
int getInt(int x, int y) {
    return ((x << 16) & 0x7FFF0000) | (y & 0x0000FFFF);
}
bool connected(int from, int to) {
    int fromx = getX(from);
    int fromy = getY(from);
    int tox = getX(to);
    int toy = getY(to);

    return (j*j) >= ((fromx-tox)*(fromx-tox)) + ((fromy-toy)*(fromy-toy));
}

void getInput() {
    int x, y;
    cin >> j;
    cin >> x >> y;
    used.push_back(getInt(x + BASE, y + BASE));

    cin >> x >> y;
    target = getInt(x + BASE, y + BASE);
    remain.push_back(target);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        remain.push_back(getInt(x + BASE, y + BASE));
    }
}

void solve() {
    while (!used.empty()) {
        int u = used.front();
        used.pop_front();

        list<int>::iterator it = remain.begin();
        for (; it != remain.end();) {
            if (connected(u, *it)) {
                used.push_back(*it);
                it = remain.erase(it);
            }
            else {
                it++;
            }
        }
    }

    list<int>::const_iterator it = remain.begin();
    for (; it != remain.end(); it++) {
        if (target == *it) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
