// https://www.facebook.com/hackercup/problems.php?pid=1523599254559737&round=742632349177460
// Facebook Hacker Cup 2015 Qualification Round
// #3. Laser Maze
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

enum { UP, RIGHT, DOWN, LEFT, WALL, EMPTY, GOAL, };
class Scene { public:
    Scene(int r_, int c_, int s_) : r(r_), c(c_), s(s_) {}
    int r, c, s/*step*/;
};

int row, col;
int sr, sc, gr, gc; // start-row ...
int count; // solution
char maze[100][101];
bool visit[100][100][4];

void input() {
    scanf("%d %d\n", &row, &col);
    for (int r = 0; r < row; r++) {
        gets(maze[r]);
        for (int c = 0; c < col; c++) {
            switch (maze[r][c]) {
                case 'S': sr = r; sc = c; maze[r][c] = EMPTY; break;
                case 'G': gr = r; gc = c; maze[r][c] = GOAL; break;
                case '.': maze[r][c] = EMPTY; break;
                case '#': maze[r][c] = WALL; break;
                case '<': maze[r][c] = LEFT; break;
                case '>': maze[r][c] = RIGHT; break;
                case '^': maze[r][c] = UP; break;
                case 'v': maze[r][c] = DOWN; break;
                default: break;
            }
        }
    }
}

bool canbe(int r, int c, int step) {
    if (r < 0) return false;
    if (r >= row) return false;
    if (c < 0) return false;
    if (c >= col) return false;
    if (maze[r][c] <= WALL) return false;
    if (visit[r][c][step%4]) return false;

    // laser
    int rr = 0;
    for (; rr < r; rr++) {
        if (maze[rr][c] < WALL && (maze[rr][c] + step) % 4 == DOWN) return false;
    }
    for (rr = r+1; rr < row; rr++) {
        if (maze[rr][c] < WALL && (maze[rr][c] + step) % 4 == UP) return false;
    }
    int cc = 0;
    for (; cc < c; cc++) {
        if (maze[r][cc] < WALL && (maze[r][cc] + step) % 4 == RIGHT) return false;
    }
    for (cc = c+1; cc < col; cc++) {
        if (maze[r][cc] < WALL && (maze[r][cc] + step) % 4 == LEFT) return false;
    }
    return true;
}

void find_maze() {
    memset(visit, 0, sizeof(bool) * 100 * 100 * 4);
    input();
    count = 0x7FFFFFFF;

    queue<Scene> Q;
    if (canbe(sr, sc, 0)) {
        Q.push(Scene(sr, sc, 0));
        visit[sr][sc][0] = true;
    }
    while (!Q.empty()) {
        Scene scene = Q.front();
        Q.pop();

        if (scene.r == gr && scene.c == gc) { // found
            count = min(count, scene.s);
            continue;
        }
        if (count <= scene.c) continue;
        if (canbe(scene.r - 1, scene.c, scene.s + 1)) { // UP
            Q.push(Scene(scene.r - 1, scene.c, scene.s + 1));
            visit[scene.r - 1][scene.c][(scene.s + 1) % 4] = true;
        }
        if (canbe(scene.r + 1, scene.c, scene.s + 1)) { // DOWN
            Q.push(Scene(scene.r + 1, scene.c, scene.s + 1));
            visit[scene.r + 1][scene.c][(scene.s + 1) % 4] = true;
        }
        if (canbe(scene.r, scene.c - 1, scene.s + 1)) { // LEFT
            Q.push(Scene(scene.r, scene.c - 1, scene.s + 1));
            visit[scene.r][scene.c - 1][(scene.s + 1) % 4] = true;
        }
        if (canbe(scene.r, scene.c + 1, scene.s + 1)) { // RIGHT
            Q.push(Scene(scene.r, scene.c + 1, scene.s + 1));
            visit[scene.r][scene.c + 1][(scene.s + 1) % 4] = true;
        }
    }
}

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        find_maze();
        if (count == 0x7FFFFFFF) {
            printf("Case #%d: impossible\n", i+1);
        }
        else {
            printf("Case #%d: %d\n", i+1, count);
        }
    }
    return 0;
}

