// http://algospot.com/judge/problem/read/BST
#include <iostream>

using namespace std;

class Tree { public:
    Tree() : key(0), left(0), right(0) {}
    ~Tree() {}
    int key;
    Tree *left, *right;
    bool operator <(const Tree &t) const {return key < t.key;}
    bool operator >(const Tree &t) const {return key > t.key;}
};

int n;
int in[101][3];
Tree tree[101];

void getInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in[i][0] >> in[i][1] >> in[i][2];
        tree[i].key = in[i][2];
        tree[i].left = &tree[in[i][0]];
        tree[i].right = &tree[in[i][1]];
    }
}

Tree *get_root() {
    bool check[101] = {false,};
    int i;
    for (i = 1; i <= n; i++) {
        check[in[i][0]] = true;
        check[in[i][1]] = true;
    }
    for (i = 1; i <= n; i++) {
        if (!check[i]) return &tree[i];
    }
    return 0; // error
}

int check_bst(Tree *t, int current) {
    const Tree *null_tree = &tree[0];
    if (t->left != null_tree) {
        current = check_bst(t->left, current);
        if (current < 0) return current;
    }
    if (current >= t->key) return -1;
    current = t->key;
    if (t->right != null_tree) {
        current = check_bst(t->right, current);
        if (current < 0) return current;
    }
    return current;
}

void solve() {
    // depth first traversal
    cout << (check_bst(get_root(), -1) > 0 ? "YES" : "NO") << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
