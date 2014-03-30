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
#include <set>
#include <vector>
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

const size_t BOARD_SIZE = 1400;
set<int> board[BOARD_SIZE]; // org

map <int, int> index_map_x; // index map x (value - index)
map <int, int> index_map_y; // index map y (value - index)

map <int, int> value_map_x; // index map x (index - value)
map <int, int> value_map_y; // index map y (index - value)

int _count = 0;
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


void makeIndexValueMap(map_type &m, map<int, int> &index_map, map<int, int> &value_map) {
    map<int, set<Line> >::iterator i = m.begin();
    int index = 0;
    for (; i != m.end(); i++, index++) {
        index_map[i->first] = index;
        value_map[index] = i->first;
    }
}

void getInput() {
    int left, top, right, bottom;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &left, &top, &right, &bottom);
        hor[top].insert(Line(left, right));
        hor[bottom].insert(Line(left, right));
        ver[left].insert(Line(top, bottom));
        ver[right].insert(Line(top, bottom));
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

int exist(int row, int from, int to) { // return height
    int size = n * 2;
    for (int i = row + 1; i < size; i++) {
        if (board[i].find(from) != board[i].end() && board[i].find(to) != board[i].end()) {
            return i - row;
        }
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

    //trace("%d %d %d %d\n", top, bottom, left, right);
    // handle overlaped
    int size = n * 2;
    for (int row = top; row < bottom ; row++) {
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
                if (height > 0 && row + height <= bottom) {
                    area -= getArea(row, row + height, from, to);
                    from = *col; // init
                }
                else {
                    from = *col; // init
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


void push_ver(int row, int from, int to) {
    map<int, set<Line> >::iterator i = ver.begin();
    for (; i != ver.end(); i++) {
        if (i->first >= from) break;
    }

    for (; i != ver.end(); i++) {
        if (to < i->first) break;
        int _col = indexof(index_map_x, i->first);
        set<Line> &lines = i->second;
        set<Line>::const_iterator it = lines.begin();
        for (; it != lines.end(); it++) {
            if (it->from <= row && row <= it->to) {
                board[indexof(index_map_y, row)].insert(_col);
            }
        }
    }
}

void push_row() {
    // left - right
    map<int, set<Line> >::iterator i = hor.begin();
    for (; i != hor.end(); i++) {
        int row = i->first;
        set<Line> &lines = i->second;
        set<Line>::const_iterator it = lines.begin();
        for (; it != lines.end(); it++) {
            int _row = indexof(index_map_y, row);
            board[_row].insert(indexof(index_map_x, it->from));
            board[_row].insert(indexof(index_map_x, it->to));

            push_ver(row, it->from, it->to);
        }
    }
}

void solve() {
    push_row();
    check();

    trace("%d %d\n", _count, maxArea);
}


int main(int argc, char *argv[]) {
    getInput();
    solve();
    return 0;
}
