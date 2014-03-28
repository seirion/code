// Problem1
// hyungyu.jang@lge.com

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <code/debug.h>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>

using namespace std;

class Line {
public:
    Line(int f, int t) : from(f), to(t) {}
    int from, to;
    bool operator<(const Line &l) const {return from < l.from;}
};

typedef map<int, set<Line> > map_type;
map<int, set<Line> > hor; // horizontal (y)
map<int, set<Line> > ver; // vertical (x)

const size_t BOARD_SIZE = 5000;
int **board;

map <int, int> index_map_x; // index map x (value - index)
map <int, int> index_map_y; // index map y (value - index)

int count = 0;
int maxArea = 0;

///////////////////////////////////////////////////////////////////////
int n;

void print(map_type &m) {
    map<int, set<Line> >::iterator i = m.begin();
    for (; i != m.end(); i++) {
        cout << i->first << " : " << endl;
        
        set<Line>::iterator j = i->second.begin();
        for (; j != i->second.end(); j++) {
            cout << "     " << j->from << " " << j->to << endl;
        }
    }
}

void makeIndexMap(map_type &m, map<int, int> &index_map) {
    map<int, set<Line> >::iterator i = m.begin();
    int index = 0;
    for (; i != m.end(); i++) {
        index_map[i->first] = index++;
    }
}

void getInput() {
    scanf("%d", &n);
    int left, top, right, bottom;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &left, &top, &right, &bottom);
        hor[top].insert(Line(left, right));
        hor[bottom].insert(Line(left, right));
        ver[left].insert(Line(top, bottom));
        ver[right].insert(Line(top, bottom));
    }

    makeIndexMap(hor, index_map_y);
    makeIndexMap(ver, index_map_x);

#if 0
    /// test
    cout << " ------- " << endl;
    map<int, int>::iterator p = index_map_x.begin();
    for (; p != index_map_x.end(); p++) {
        cout << p->first << " ";
    }
    cout << endl;
#endif

}


int indexof(map<int, int> &index_map, int key) {
    return index_map[key];
}

void push_hor(map_type &m) {
    map<int, set<Line> >::iterator i = m.begin();
    int row = 0;
    for (; i != m.end(); i++, row++) {
        set<Line>::iterator j = i->second.begin();
        for (; j != i->second.end(); j++) {
            int from = indexof(index_map_x, j->from);
            int to = indexof(index_map_x, j->to);
            for (int k = from; k <= to; k++)
                board[row][k]++;
        }
    }
}

void push_ver(map_type &m) {
    map<int, set<Line> >::iterator i = m.begin();
    int col = 0;
    for (; i != m.end(); i++, col++) {
        set<Line>::iterator j = i->second.begin();
        for (; j != i->second.end(); j++) {
            int from = indexof(index_map_y, j->from);
            int to = indexof(index_map_y, j->to);
            for (int k = from; k <= to; k++)
                board[k][col]++;
        }
    }
}

void check() {
    int size = n * 2;
    for (int row = 0; row < size; row++) {
        int from = -1;
        for (int col = 0; col < size; col++) {
            if (board[row][col] <= 1) continue;
            if (from == -1) from = col;
            else {
                to = col;


                from = -1;
            }
        }
    }
}


void solve() {
    push_hor(hor);
    push_ver(ver);


    for (int i = 0; i < hor.size(); i++) { // debug
        for (int j = 0; j < ver.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    check();
}


void alloc(const size_t size) {
    board = new int *[size];
    for (int i = 0; i < size; i++) {
        board[i] = new int[size];
        memset(board[i], 0, sizeof(int) * size);
    }
}
void release(const size_t size) {
    for (int i = 0; i < size; i++)
        delete [] board[i];
    delete [] board;
}

int main(int argc, char *argv[]) {
    alloc(BOARD_SIZE);
    getInput();
    solve();
    release(BOARD_SIZE);
    return 0;
}
