// http://algospot.com/judge/problem/read/TRAVERSAL
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_SIZE = 101;
int n;
queue<int> pre;     // prefix
int in[MAX_SIZE];   // infix
int dict[1001];     // 1 ~ 1000

void getInput() {
    cin >> n;
    int i;
    for (i = 0; i < n; i++) {
        cin >> in[i];
        pre.push(in[i]);
    }
    for (i = 0; i < n; i++) {
        cin >> in[i];
        dict[in[i]] = i;
    }
}

void findPostfix(vector<int> &out, int from, int to) {
    if (from > to) return;
    if (from == to) {
        out.push_back(pre.front());
        pre.pop();
        return;
    }

    int root = pre.front();
    int i = dict[root];
    pre.pop();
    
    findPostfix(out, from, i-1);// left
    findPostfix(out, i+1, to);  // right
    out.push_back(root);
}

void solve() {
    vector<int> out;
    findPostfix(out, 0, n-1);

    int i = 0;
    cout << out[0];
    for (i = 1; i < n; i++) cout << " " << out[i];
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
