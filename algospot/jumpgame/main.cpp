// http://algospot.com/judge/problem/read/JUMPGAME
#include <iostream>
#include <set>

using namespace std;

class Goto {
public:
    Goto(char i, char j) : row(i), col(j)  {}
    char row, col;
    bool operator <(const Goto& g) const {
        return row == g.row ? col < g.col : row < g.row;
    }
};

int n;
int in[100][100];


void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> in[i][j];
        }
    }
}

void solve() {
    set<Goto> v0, v1;
    v0.insert(Goto(0,0));
    bool solved = false;

    do {
        set<Goto>::const_iterator it = v0.begin();
        for (; it != v0.end(); it++) {
            int i = it->row;
            int j = it->col;
            int value = in[i][j];
            if (i + value < n) {
                if (i + value == n-1 && j == n-1) {
                    solved = true;
                    break;
                }
                v1.insert(Goto(i + value, j));
            }
            if (j + value < n) {
                if (i == n-1 && j + value == n-1) {
                    solved = true;
                    break;
                }
                v1.insert(Goto(i, j + value));
            }
        }

        v0.clear();
        v0.swap(v1);
    } while (!v0.empty());

    if (solved) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
