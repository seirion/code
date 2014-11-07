// SRM 637 ConnectingGameDiv2
// http://community.topcoder.com/stat?c=problem_statement&pm=13507&rd=16080
#include <cstdio> // for debugging
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <functional>


using namespace std;


class ConnectingGameDiv2 {
public:
    ConnectingGameDiv2() {
        memset(graph, 0, sizeof(bool) * 256 * 256);
        memset(cost, 0, sizeof(int) * 256);
    }
public:
    int getmin(const vector<string> board);
    class Node { public:
        Node(int i_, int c_) : i(i_), c(c_) {}
        int i, c;
        bool operator >(const Node &n) const {
            return (c == n.c ? i > n.i : c > n.c);
        }
    };

private:
    void build_graph(const vector<string> &board);
    int min_cost(const vector<string> &board); // dijstra

private:
    bool graph[256][256];
    int cost[256];
};

int ConnectingGameDiv2::getmin(vector<string> board) {
    build_graph(board);
    return min_cost(board);
}

void ConnectingGameDiv2::build_graph(const vector<string> &board) {
    int row = board.size();
    int col = board[0].size();

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            char v = board[r][c];
            cost[v]++;
            if (c == 0) { graph[0][v] = true; }
            if (c == col - 1) { graph[v][255] = true; }

            int left = max(0, c-1); int right = min(col-1, c+1);
            int top = max(0, r-1);  int bottom = min(row-1, r+1);
            for (int rr = top; rr <= bottom; rr++) {
                for (int cc = left; cc <= right; cc++) {
                    if (v != board[rr][cc]) {
                        graph[v][board[rr][cc]] = true; // connected
                    }
                }
            }
        }
    }
    // make it MAX_VALUE except 0 and 255
    for (int i = 1; i <= 254; i++) { if (cost[i] == 0) cost[i] = 0x7FFFFFFF; }
}

int ConnectingGameDiv2::min_cost(const vector<string> &board) {
    bool visit[256] = {false};
    int length_to[256] = {0,}; // init MAX_VALUE
    for (int i = 1; i < 256; i++) length_to[i] = 0x7FFFFFFF;

    priority_queue<Node, vector<Node>, greater<Node> > Q;
    Q.push(Node(0, 0));

    while (!Q.empty()) {
        int now = Q.top().i;
        Q.pop();
        if (now == 255) break;
        if (visit[now]) continue;
        visit[now] = true;

        for (int i = 1; i < 256; i++) { // select least
            if (!visit[i] && graph[now][i]) {
                int length = length_to[now] + cost[i];
                if (length_to[i] > length) {
                    length_to[i] = length;
                    Q.push(Node(i, length));
                }
            }
        }
    }

    return length_to[255];
} 

int main() {
    string test0[] = {"AA", "BB"};
    string test1[] = {"AAB", "ACD", "CCD"};
    string test2[] = {"iii", "iwi", "iii"};
    string test3[] = {"rng58", "Snuke", "Sothe"};
    string test4[] = {"yyAArJqjWTH5", "yyEEruYYWTHG", "hooEvutpkkb2", "OooNgFFF9sbi", "RRMNgFL99Vmm", "R76XgFF9dVVV", "SKnZUPf88Vee"};
 
    {
        ConnectingGameDiv2 game;
        vector<string> board;
        board.push_back(test0[0]);
        board.push_back(test0[1]);
        cout << game.getmin(board) << "\n";
    }
 
    {
        ConnectingGameDiv2 game;
        vector<string> board;
        board.push_back(test1[0]);
        board.push_back(test1[1]);
        board.push_back(test1[2]);
        cout << game.getmin(board) << "\n";
    }
    //
    {
        ConnectingGameDiv2 game;
        vector<string> board;
        board.push_back(test2[0]);
        board.push_back(test2[1]);
        board.push_back(test2[2]);
        cout << game.getmin(board) << "\n";
    }
    //
    {
        ConnectingGameDiv2 game;
        vector<string> board;
        board.push_back(test3[0]);
        board.push_back(test3[1]);
        board.push_back(test3[2]);
        cout << game.getmin(board) << "\n";
    }
    //
    {
        ConnectingGameDiv2 game;
        vector<string> board;
        board.push_back(test4[0]);
        board.push_back(test4[1]);
        board.push_back(test4[2]);
        board.push_back(test4[3]);
        board.push_back(test4[4]);
        board.push_back(test4[5]);
        board.push_back(test4[6]);
        cout << game.getmin(board) << "\n";
    }
 
    return 0;
}
