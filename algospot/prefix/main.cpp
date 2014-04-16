// http://algospot.com/judge/problem/read/PREFIX
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
string in[3000];

class Tree {
public:
    Tree(Tree* p = 0) : parent(p), depth(0), count(0), size(0) {
		memset(child, 0, sizeof(Tree*) * 26);
		buffer[0] = '\0';
    }
    //~Tree() { size_t s = child.size(); for (int i = 0; i < s; i++) delete child[i]; }
    ~Tree() { for (int i = 0; i < 26; i++) delete child[i]; }
    Tree *parent;
    int depth;
    int count;
    char buffer[201];
    int size; // buffer size
    Tree* child[26];
};

Tree *root = 0;
Tree *solution[201];

void getin(const string str) {
    int s = min(M, (int)str.size());
    Tree *node = root;
	//int index = find(node, str);
    for (int i = 0; i < s; i++) {
    }
}

void getInput() {
    root = new Tree();
    cin >> N >> M;
    cin.get();
    char buffer[201];
    for (int i = 0; i < N; i++) {
        gets(buffer);
		in[i] = buffer;
    }
	sort(in, in + N);
    for (int i = 0; i < N; i++) {
		getin(in[i]);
	}
}


void printSolution(int i) {
}

void search(Tree *node) {
}

void solve() {
    memset(solution, 0, sizeof(Tree*) * 201);

    for (int i = 1; i <= M; i++) {
    	//search(root);
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
