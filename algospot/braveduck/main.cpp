// http://algospot.com/judge/problem/read/BRAVEDUCK
#include <iostream>
#include <deque>
#include <list>

using namespace std;


class Pos { public:
    Pos() {}
    Pos(int x_, int y_) : x(x_), y(y_) {}
    int x, y;
    bool operator==(const Pos& p) {return(x == p.x && y == p.y);}
};

int j, n;
Pos target;
deque<Pos> used;
list<Pos> remain;

bool connected(const Pos &from, const Pos &to) {
    return (j*j) >= ((from.x-to.x)*(from.x-to.x)) + ((from.y-to.y)*(from.y-to.y));
}

void getInput() {
    used.clear();
    remain.clear();
    int x, y;
    cin >> j;
    cin >> x >> y;
    used.push_back(Pos(x, y));

    cin >> target.x >> target.y;

    remain.push_back(target);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        remain.push_back(Pos(x, y));
    }
}

void solve() {
    while (!used.empty()) {
        Pos u = used.front();
        used.pop_front();

        list<Pos>::iterator it = remain.begin();
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

    list<Pos>::const_iterator it = remain.begin();
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
