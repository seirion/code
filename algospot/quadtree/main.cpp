// http://algospot.com/judge/problem/read/QUADTREE
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char buffer[1001];

class Tree { public:
    Tree() {memset(child, 0, sizeof(Tree*) * 4);}
    ~Tree() {for(int i = 0; i < 4; i++) delete child[i];}
    char color[4];
    Tree *child[4];
    void print() {
        for(int i = 0; i < 4; i++) {
            cout << color[i];
            if (color[i] == 'x') child[i]->print();
        }
    }
    void upsidedown() {
        for(int i = 0; i < 4; i++) {
            if (color[i] == 'x') child[i]->upsidedown();
        }
        char t = color[0]; color[0] = color[2]; color[2] = t;
        t = color[1]; color[1] = color[3]; color[3] = t;
        Tree *tt = child[0]; child[0] = child[2]; child[2] = tt;
        tt = child[1]; child[1] = child[3]; child[3] = tt;
    }
    char *makeup(char *buf) {
        for(int i = 0; i < 4; i++) {
            color[i] = buf[0]; buf++;
            if (color[i] == 'x') {
                child[i] = new Tree();
                buf = child[i]->makeup(buf);
            }
        }
        return buf;
    }
};

void getInput() {
    cin >> n;
    gets(buffer);
}


void solve() {
    if (buffer[0] != 'x') {
        cout << buffer[0] << endl;
        return;
    }
    Tree t;
    t.makeup(buffer+1);
    //cout << "x"; t.print(); cout << endl; // TEST
    t.upsidedown();
    cout << "x"; t.print(); cout << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
