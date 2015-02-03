// http://algospot.com/judge/problem/read/HARVEST
// http://en.wikipedia.org/wiki/Longest_increasing_subsequence
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {public:
    Node() {}
    int row, col, index;
};

int row, col, n;
Node node[20000];

bool less_by_col(const Node &a, const Node& list) {
    if (a.col == list.col) return a.row < list.row;
    return a.col < list.col;
}

bool less_by_row(const Node &a, const Node& list) {
    if (a.row == list.row) return a.col < list.col;
    return a.row < list.row;
}

void input() {
    scanf("%d %d %d", &row, &col, &n);
    for (int i = 0; i < n; i++) {
        int r, c;
        scanf("%d %d", &node[i].row, &node[i].col);
    }
}

int lis(vector<int> &arr) { // longest increasing subsequence

    vector<int> list;
    list.push_back(0);

    for (int i = 1; i < arr.size(); i++) {
        if (arr[list.back()] < arr[i]) {
            list.push_back(i);
            continue;
        }

        int from(0), to(list.size()-1);
        while (from < to) {
            int mid = (from + to) / 2;
            if (arr[list[mid]] < arr[i]) {
                from = mid + 1;
            }
            else {
                to = mid;
            }
        }
 
        list[from] = i;
    }
 
    return list.size();
}

void solve() {
    sort(node, node+n, less_by_col);
    int i;
    for (i = 0; i < n; i++) {
        node[i].index = i;
    }

    sort(node, node+n, less_by_row);
    int counter = 1;
    int m = node[i].index;
    vector<int> v(n, 0);
    for (i = 0; i < n; i++) {
        v[i] = node[i].index;
    }

    printf("%d\n", lis(v));
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
