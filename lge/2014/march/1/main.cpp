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
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Line {
public:
    Line(int f, int t) : from(f), to(t) {}
    int from, to;
    bool operator<(const Line &l) const {return from < l.from;}
};

typedef map<int, vector<Line> > map_type;
map<int, vector<Line> > hor; // horizontal (y)
map<int, vector<Line> > ver; // vertical (x)

const size_t BOARD_SIZE = 10000;
set<int> board[BOARD_SIZE];
set<int> board_temp[BOARD_SIZE];

map <int, int> index_map_x; // index map x (value - index)
map <int, int> index_map_y; // index map y (value - index)

map <int, int> value_map_x; // index map x (index - value)
map <int, int> value_map_y; // index map y (index - value)

int _count = 0;
int maxArea = 0;

///////////////////////////////////////////////////////////////////////
int n;

void print(map_type &m) {
    map<int, vector<Line> >::iterator i = m.begin();
    for (; i != m.end(); i++) {
        cout << i->first << " : " << endl;
        
        vector<Line>::iterator j = i->second.begin();
        for (; j != i->second.end(); j++) {
            cout << "     " << j->from << " " << j->to << endl;
        }
    }
}

void makeIndexValueMap(map_type &m, map<int, int> &index_map, map<int, int> &value_map) {
    map<int, vector<Line> >::iterator i = m.begin();
    int index = 0;
    for (; i != m.end(); i++, index++) {
        index_map[i->first] = index;
        value_map[index] = i->first;
    }
}

void getInput() {
    scanf("%d", &n);
    int left, top, right, bottom;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &left, &top, &right, &bottom);
        hor[top].push_back(Line(left, right));
        hor[bottom].push_back(Line(left, right));
        ver[left].push_back(Line(top, bottom));
        ver[right].push_back(Line(top, bottom));
    }

    makeIndexValueMap(hor, index_map_y, value_map_y);
    makeIndexValueMap(ver, index_map_x, value_map_x);
}


int indexof(map<int, int> &index_map, int key) {
    return index_map[key];
}

int valueof(map<int, int> &value_map, int key) {
    return value_map[key];
}

void push_hor(map_type &m) {
    map<int, vector<Line> >::iterator i = m.begin();
    int row = 0;
    for (; i != m.end(); i++, row++) {
        vector<Line>::iterator j = i->second.begin();
        for (; j != i->second.end(); j++) {
            int from = indexof(index_map_x, j->from);
            int to = indexof(index_map_x, j->to);
            for (int k = from; k <= to; k++) {
                if (board_temp[row].find(k) == board_temp[row].end()) {
                    board_temp[row].insert(k); // vertex
                }
                else {
                    board[row].insert(k); // real point
                }
            }
        }
    }
}

void push_ver(map_type &m) {
    map<int, vector<Line> >::iterator i = m.begin();
    int col = 0;
    for (; i != m.end(); i++, col++) {
        vector<Line>::iterator j = i->second.begin();
        for (; j != i->second.end(); j++) {
            int from = indexof(index_map_y, j->from);
            int to = indexof(index_map_y, j->to);
            for (int k = from; k <= to; k++)
                if (board_temp[k].find(col) == board_temp[k].end()) {
                    board_temp[k].insert(col); // vertex
                }
                else {
                    board[k].insert(col); // real point
                }
        }
    }
}

int exist(int row, int from, int to) { // return height
    int size = n * 2;
    for (int i = row + 1; i < size; i++) {
        if (board[i].find(from) != board[i].end() && board[i].find(to) != board[i].end()) return i - row;
    }
    return 0; // not exist
}

int simpleArea(int top, int bottom, int left, int right) {
    int width = valueof(value_map_x, right) - valueof(value_map_x, left);
    int height = valueof(value_map_y, bottom) - valueof(value_map_y, top);
    return width * height;
}

int getArea(int top, int bottom, int left, int right) {
    int area = simpleArea(top, bottom, left, right);

    // handle overlaped
    int size = n * 2;
    for (int row = top; row <= bottom ; row++) {
        int from = -1;
        int to;
        set<int>::const_iterator col = board[row].begin();
        for (; col != board[row].end(); col++) {
            if (*col < left) continue;
            if (*col > right) break;

            if (from == -1) from = *col;
            else {
                to = *col;
                if (from == left && to == right) continue;
                int height = exist(row, from, to);
                if (height > 0) {
                    area -= simpleArea(row, row + height, from, to);
                }
            }
        }
    }

    return area;
}

void check() {
    int size = n * 2;
    for (int row = 0; row < size; row++) {
        int from = -1;
        int to;
        set<int>::const_iterator col = board[row].begin();
        for (; col != board[row].end(); col++) {
            if (from == -1) from = *col;
            else { // exist another ?
                to = *col;
                int height = exist(row, from, to);
                if (height > 0) {
                    _count++;
                    int area = getArea(row, row + height, from, to);
                    maxArea = max(maxArea, area);
                    from = *col; // init
                }
            }
        }
    }
}


void solve() {
    push_hor(hor);
    push_ver(ver);
    check();

    trace("%d %d\n", _count, maxArea);
}


int main(int argc, char *argv[]) {
    getInput();
    solve();
    return 0;
}
