// http://algospot.com/judge/problem/read/BOOKSTORE
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Node {
public:
    Node(int p, int po) : price(p), point(po) {}
    int price, point;
    bool operator <(const Node &n) const {return point < n.point;}
    bool operator >(const Node &n) const {return point > n.point;}
};

int book = 0; // # books
int numStore = 0; // # store
int mini;
vector<Node> store[100];

void getInput() {
    int i;
    for (i = 0; i < numStore; i++) { store[i].clear(); }

    int price, point;
    cin >> book >> numStore;
    for (i = 0; i < book; i++) {
        for (int j = 0; j < numStore; j++) {
            cin >> price >> point;
            store[j].push_back(Node(price, point));
        }
    }
}

int getMin(vector<Node> &node, int index, int remain, size_t size) {
    if (index == size) return;

    int price(0), point(0), remain(0);
    size_t s = node.size();
    for (int i = 0; i < s; i++) {
        price += node[i].price;
        point += node[i].point;
    }

    return 0;
}

void solve() {
    mini = 0X7FFFFFFF;
    for (int i = 0; i < numStore; i++) {
        sort(store[i].begin(), store[i].end(), greater<Node>());
        mini = min(mini, getMin(store[i], 0, 0, store[i].size()));
#if 0
    size_t s = store[i].size();
    for (int j = 0; j < s; j++) {
        cout << " * " << store[i][j].point << " " << store[i][j].price << endl;
    }
    cout << endl;
#endif
    }

    cout << mini << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
