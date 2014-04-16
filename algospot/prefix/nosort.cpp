// http://algospot.com/judge/problem/read/PREFIX
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

int N, M;

class Tree {
public:
    Tree(Tree* p = 0) : parent(p), value (0), depth(0), count(0) {
        memset(tree, 0, sizeof(Tree*) * 26);
    }
    ~Tree() { for (int i = 0; i < 26; i++) delete tree[i]; }
    Tree *parent;
    char value;
    int depth;
    int count;
    Tree *tree[26]; // children
};

Tree *root = 0;
Tree *solution[201];


void getin(char *buffer) {
    int s = min(M, (int)strlen(buffer));
    Tree *node = root;
    for (int i = 0; i < s; i++) {
        int index = buffer[i] - 'a';
        if (!node->tree[index]) {
            node->tree[index] = new Tree(node);
            node->tree[index]->value = buffer[i];
            node->tree[index]->depth = i + 1;
        }
        Tree *child = node->tree[index];
        child->count++;
        node = child;
    }
}

void getInput() {
    root = new Tree();
    cin >> N >> M;
    cin.get();
    char buffer[201];
    for (int i = 0; i < N; i++) {
        gets(buffer);
        getin(buffer);
    }
}


void printSolution(int i) {
    Tree *node = solution[i];
    char buffer[201];
    buffer[200] = '\0';
    int index = 199;
    while (node->parent) {
        buffer[index--] = node->value;
        node = node->parent;
    }
    cout << buffer + index + 1 << endl;
}

bool compare(const Tree* f, const Tree* s) { // greater()
    if (f && s) {
        if (f->count == s->count) return f->value < s->value;
        return f->count > s->count;
    }
    return (f != 0);
}

void search(Tree *node, int target) {
    if (node->depth > target) return;
    if (node->depth == target) {
		if(!solution[target] || solution[target]->count < node->count) {
        	solution[target] = node;
		}
		return;
    }

    for (int i = 0; i < 26; i++) {
        if (node->tree[i]) {
            if (!solution[target] || solution[target]->count < node->tree[i]->count) {
                search(node->tree[i], target);
            }
        }
    }
}

void solve() {
    memset(solution, 0, sizeof(Tree*) * 201);

    // depth first search
    for (int i = 1; i <= M; i++) {
        //search(root, i);
        //printSolution(i);
    }
}

void clear() {
    delete root;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve(); clear();}
    return 0;
}
