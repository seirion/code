// http://algospot.com/judge/problem/read/MOVE
#include <iostream>
#include <cstring>
#include <list>
#include <set>

using namespace std;

class Line { public:
    Line(int t, int c) : to(t), cost(c) {}
    int to, cost;
    bool operator <(const Line& l) const { return to < l.to; }
};

int n;
int length_to[10000];
set<Line> line[10000];

class Node { public:
    Node(int i) : index(i) {}
    int index;
    bool operator <(const Node& l) const { 
        return (length_to[index] == length_to[l.index]) ? index < l.index :
            length_to[index] < length_to[l.index];
    }
};

void getInput() {
    int m, from, to, cost;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        line[from].insert(Line(to, cost));
        line[to].insert(Line(from, cost));
    }
}

int length(int from, int to) {
    set<Line>::iterator i = line[from].find(Line(to, 0));
    return i->cost;
}

void solve() { // dijkstra
    int i;
    memset(length_to, 0x7F, sizeof(int) * 10000);
    length_to[0] = 0;

    set<Node> Q;
    for (i = 0; i < n; i++) {
        Q.insert(i);
    }

    while (!Q.empty()) {
        Node node = *Q.begin();
        Q.erase(Q.begin());
        if (node.index == n-1) break;
        set<Line>::const_iterator it = line[node.index].begin();
        for (; it != line[node.index].end(); it++) {
            int dist = length_to[node.index] + length(node.index, it->to);
            if (length_to[it->to] > dist) {
                Q.erase(Node(it->to));
                length_to[it->to] = dist;
                Q.insert(Node(it->to));
            }
        }
    }

    cout << length_to[n-1] << endl;
    for (i = 0; i < n; i++) { // release
        line[i].clear();
    }
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
