// http://lgecodejam.com
// lge code jam August, 2014
// problem.3
// hyungyu.jang@lge.com


#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <trace/trace.h>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
typedef map<int, int> MII;

int page, link, start, limit;
MII in[1002]; // index, count
int way[10001][1002];
const int DEVIDER [] = {
    1, 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
};


void count(int from) {
    memset(way, 0, sizeof(int) * 10001 * 1002);
    int i;
    for (i = 1; i <= page; i++) {
        if (in[from][i]) way[1][i] = in[from][i];
    }

    for (i = 2; i <= limit; i++) {
        for (int index = 1; index <= page; index++) {
            int c = way[i-1][index];
            if (c == 0) continue;
            if (c % DEVIDER[from] == 0) continue;

            MII::iterator j = in[index].begin();
            for (; j != in[index].end(); j++) {
                int to = j->first;
                int cc = j->second;
                way[i][to] += (c * cc) % DEVIDER[from];
            }
            way[i][index] %= DEVIDER[from];
        }
    }

    int solution(0);
    for (i = 1; i <= limit; i++) {
        solution += way[i][1];
    }
    printf("%d ", solution % DEVIDER[from]);

}

void solve() {
    int i, from, to, solution(0);
    scanf("%d %d %d %d", &page, &link, &start, &limit);
    for (i = 0; i < link; i++) {
        scanf("%d %d", &from, &to);
        in[from][to]++;
    }

    start += 1;
    for (i = 2; i <= start; i++) {
        count(i);
    }
    printf("\n");
}

void clear() {
    for (int i = 1; i <= page; i++) {
        in[i].clear();
    }
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve(); clear();}
    return 0;
}
