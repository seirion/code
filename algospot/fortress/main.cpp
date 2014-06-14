// http://algospot.com/judge/problem/read/FORTRESS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


class Wall { public:
    Wall() {}
    void set(int x_, int y_, int r_) {x = x_; y = y_; r = r_;}
    int x, y, r;
    bool operator >(const Wall &w) const { return r > w.r; }
};

Wall in[100];

class Tree { public:
    Tree(int i): index(i), max_depth(-1), max_walls(-1) {}
    int index, max_depth, max_walls;
    vector<Tree> child;
    bool isParentOf(int i) const {
        const Wall &p = in[index];
        const Wall &c = in[i];
        int length_square = (p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y);
        return (length_square <= p.r * p.r);
    }
    int getMaxWalls() { // historic
        if (max_walls != -1) return max_walls;
        size_t s = child.size();
        if (s == 0) {
            max_walls = 0;
        }
        else {
            vector<int> childDepth;
            for (int i = 0; i < s; i++) {
                childDepth.push_back(child[i].getMaxDepthOfChild() + 1);
                max_walls = max(max_walls, child[i].getMaxWalls());
            }
            if (s > 1) {
                sort(childDepth.begin(), childDepth.end(), greater<int>());
                max_walls = max(max_walls, childDepth[0] + childDepth[1]);
            }
        }
        return max_walls;
    }
    int getMaxDepthOfChild() {
        if (max_depth != -1) return max_depth;
        int max_depth = 0;
        size_t s = child.size();
        for (int i = 0; i < s; i++) {
            max_depth = max(max_depth, child[i].getMaxDepthOfChild() + 1);
        }
        return max_depth;
    }
};

int n;
Tree root(0);

void getInput() {
    cin >> n;
    int x, y, r;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        in[i].set(x, y, r);
    }
    sort(in, in+n, greater<Wall>());
}

void push(Tree &tree, int index) {
    size_t s = tree.child.size();
    for (int i = 0; i < s; i++) {
        if (tree.child[i].isParentOf(index)) {
            push(tree.child[i], index);
            return;
        }
    }
    tree.child.push_back(Tree(index));
}

void solve() {
    root.child.clear();
    root.max_depth = -1;
    root.max_walls = -1;

    for (int i = 1; i < n; i++) {
        push(root, i);
    }

    //cout << root.getMaxWalls() << endl;
    cout << max(root.getMaxWalls(), root.getMaxDepthOfChild()) << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
