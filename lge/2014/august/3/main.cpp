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
typedef long long int64;

const int64 DEVIDER [] = {
    1, 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
};
const int64 ALL = 2ll * 3ll * 5ll * 7ll * 11ll * 13ll * 17ll * 19ll * 23ll * 29ll;

int page, link, start, limit;
MII in[1002]; // index, count
int64 way[10001][1002];
int64 _length[12];


void count(int from) {
    memset(way, 0, sizeof(int64) * 10001 * 1002);
    int i;
    for (i = 1; i <= page; i++) {
        if (in[from][i]) way[1][i] = in[from][i];
    }

    for (i = 2; i <= limit; i++) {
        for (int index = 1; index <= page; index++) {
            int64 c = way[i-1][index];
            if (c == 0) continue;

            MII::iterator j = in[index].begin();
            for (; j != in[index].end(); j++) {
                int to = j->first;
                int64 cc = j->second;
                way[i][to] += (c *cc) % ALL;
            }
            //way[i][index] %= ALL;
        }
    }

    for (i = 1; i <= limit; i++) {
        for (int j = 2; j <= start; j++) {
            _length[j] += way[i][j] % DEVIDER[j];
        }
    }

    for (i = 2; i <= start; i++) {
        printf("%d ", _length[i] % DEVIDER[i]);
    }
    printf("\n");

}

void solve() {
    memset(_length, 0, sizeof(int64) * 12);
    int i, from, to, solution(0);
    scanf("%d %d %d %d", &page, &link, &start, &limit);
    for (i = 0; i < link; i++) {
        scanf("%d %d", &from, &to);
        in[to][from]++; // reverse
    }

    start++;
    count(1);
}

void clear() {
    for (int i = 1; i <= page; i++) {
        in[i].clear();
    }
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve(); clear(); }
    return 0;
}
