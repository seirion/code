// http://algospot.com/judge/problem/read/ROUTING
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

class Line { public:
    Line(int t, double c) : to(t), cost(c) {}
    int to;
    double cost;
    bool operator <(const Line& l) const { return to < l.to; }
};

int n;
bool visit[10000];
vector<Line> line[10000];

class Node { public:
    Node(int i, double c) : index(i), cost(c) {}
    int index;
    double cost;
    bool operator >(const Node& l) const { 
        return cost > l.cost;
    }
};

void getInput() {
    int m, from, to;
    double cost;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        line[from].push_back(Line(to, cost));
        line[to].push_back(Line(from, cost));
    }
}

void solve() {
    int i;
    memset(visit, 0, sizeof(bool) * 10000);

    priority_queue<Node, vector<Node>, greater<Node> > Q;
    Q.push(Node(0, 1.0));

    double solution = 1.0;
    while (!Q.empty()) {
        Node node = Q.top();
        Q.pop();
        if (visit[node.index]) continue;
        if (node.index == n-1) {
            solution = node.cost;
            break;
        }
        visit[node.index] = true;
        vector<Line>::const_iterator it = line[node.index].begin();
        for (; it != line[node.index].end(); it++) {
            if (!visit[it->to]) {
                Q.push(Node(it->to, node.cost * it->cost));
            }
        }
    }

    printf("%0.10f\n", solution);
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
