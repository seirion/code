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


int findDiff(const char* str1, const char* str2) {
    int pos = 0;
    while (str1[pos] && str2[pos]) {
        if(str1[pos] != str2[pos]) return pos;
        pos++;
    }
    return pos;
}

void put(Tree *node, const char* str, int size, int index) {
    if (!node->child[index]) { // put all
        Tree* child = new Tree(node);
        node->child[index] = child;
        child->depth = node->depth + node->size;
        child->count = 1;
        strcpy(child->buffer, str);
        child->size = size;
        return;
    }
    Tree *child = node->child[index];
    int pos = findDiff(child->buffer, str);
    if (pos < child->size) { // split
        Tree *temp = new Tree(node);
        temp->depth = child->depth;
        temp->count = child->count + 1;
        strncpy(temp->buffer, child->buffer, pos);
        temp->buffer[pos] = '\0';
        temp->size = pos;
        temp->child[child->buffer[pos] - 'a'] = child;
        node->child[index] = temp;

        child->parent = temp;
        child->depth += pos;
        char tb[201];
        strcpy(tb, child->buffer + pos);
        strcpy(child->buffer, tb);
        child->size -= pos;

        put(temp, str + pos, size - pos, str[pos] - 'a');
    }
    else { // put next
        child->count++;
        if (pos== size) return;
        else put(child, str + pos, size - pos, str[pos] - 'a');
    }
}


void getin(const string& str) {
    int s = min(M, (int)str.size());
    Tree *node = root;
	put(root, str.c_str(), s, str[0] - 'a');
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
    char buffer [201];
    buffer[200] = '\0';
    Tree *node = solution[i];
    int index = 200;
    while (node->parent) {
        int length = node->size;
        if (node->depth + node-> size > i) {
            length = i - node->depth;
        }
        index -= length;
        strncpy(buffer + index, node->buffer, length);
        node = node->parent;
    }

    cout << buffer + 200 - i << endl;
}

void search(Tree *node, int target) {
    if (node->depth > target) return;
    if (node->depth + node->size >= target) { // solution
        if(!solution[target] || solution[target]->count < node->count) {
            solution[target] = node;
        }
        return;
    }
    // else
    for (int i = 0; i < 26; i++) {
        if (node->child[i]) {
            if (!solution[target] || solution[target]->count < node->child[i]->count) {
                search(node->child[i], target);
            }
        }
    }
}

void solve() {
    memset(solution, 0, sizeof(Tree*) * 201);

    for (int i = 1; i <= M; i++) {
    	search(root, i);
        printSolution(i);
    }
}

void clear() {
    delete root;
}

int main(int argc, char* argv[]) {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve(); clear();}
    return 0;
}
