// http://algospot.com/judge/problem/read/PREFIX
#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

int N, M;

class Tree {
public:
    Tree(Tree* p = 0) : parent(p), value (0), depth(0), count(0) {
        memset(tree, 0, sizeof(Tree*) * 26);
    }
    ~Tree() {for (int i = 0; i < 26; i++) delete tree[i];}
    Tree *parent;
    char value;
    int depth;
    int count;
    Tree *tree[26]; // children
};

Tree *root = 0;
Tree *solution[201];
int solved;


void getin(char *buffer) {
    int s = min(M, (int)strlen(buffer));
    Tree *tree = root;
    for (int i = 0; i < s; i++) {
        int index = buffer[i] - 'a';
        if (!tree->tree[index]) {
            tree->tree[index] = new Tree(tree);
            tree->tree[index]->value = buffer[i];
            tree->tree[index]->depth = i + 1;
        }
        Tree *child = tree->tree[index];
        child->count++;
        tree = child;
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

void solve() {
    memset(solution, 0, sizeof(Tree*) * 201);
    solved = 0;

    // breadth first search
    deque<Tree *> de;
    de.push_back(root);
    int depth = 0;
    while(!de.empty()) {
        Tree *node = de.front();
        de.pop_front();
        depth = node->depth;
        if (!solution[depth] || solution[depth]->count < node->count) {
            solution[depth] = node;
        }

        for (int i = 0; i < 26; i++) {
            if (node->tree[i]) de.push_back(node->tree[i]);
        }
    }

    for (int i = 1; i <= M; i++) {
        printSolution(i);
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
