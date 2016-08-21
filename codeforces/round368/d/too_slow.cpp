#include <iostream>
#include <set>
#include <vector>

using namespace std;

int row, col, query, re(0);
set <int> s[1001];

struct T {
    int i, a, b, c;
    T (int i_, int a_, int b_, int c_ = 0) : i(i_), a(a_), b(b_), c(c_) {}
};

vector<T> v;

bool put(int r, int c) {
    int before = s[r].size();
    s[r].insert(c);
    int after = s[r].size();
    if (before < after) re++;
    return before < after;
}

bool remove(int r, int c) {
    int before = s[r].size();
    s[r].erase(c);
    int after = s[r].size();
    if (after < before) re--;
    return after < before;
}

void invert(int r) {
    int before = s[r].size();
    int now = 1;
    set<int> temp;

    for (int x : s[r]) {
        while (now < x) {
            temp.insert(now++);
        }
        now = x + 1;
    }

    while (now <= col) {
        temp.insert(now++);
    }

    s[r].swap(temp);
    int after = s[r].size();

    re = re + after - before;
}

void clear(int now, int r) {

    int index = v.size() - 1;
    while (0 <= index) {
        T t = v[index--];
        if (t.i == r) break;
        int op = t.a;
        switch(t.a) {
            case 1: remove(t.b, t.c); op = 2; break;
            case 2: put(t.b, t.c); op = 1; break;
            case 3: invert(t.b); op = 3; break;
            default : break;
        }
        v.push_back(T(now, op, t.b, t.c));
    }
}

int main() {
    cin >> row >> col >> query;

    int index = 0;

    while (query--) {
        index++;

        int a, b, c;
        cin >> a;
        bool valid = true;
        switch (a) {
            case 1:
                cin >> b >> c;
                valid = put(b, c);
                break;
            case 2:
                cin >> b >> c;
                valid = remove(b, c);
                break;
            case 3:
                cin >> b;
                invert(b);
                break;
            case 4:
                cin >> b;
                clear(index, b);
                break;
            default : break;
        }
        if (!valid) a = 5;
        if (a != 4) v.push_back(T(index, a, b, c));
        cout << re << endl;
    }

    return 0;
}
