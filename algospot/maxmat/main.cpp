// http://algospot.com/judge/problem/read/MAXMAT
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
int in[200][200];
int acc[200][201];

void input() {
    scanf("%d", &n);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            scanf("%d", &in[r][c]);
        }
    }
    memset(acc, 0, sizeof(int) * 200 * 201);
}

int max_subarray(const vector<int> &v) {
    int max_so_far = v[0], max_ending_here = v[0];
    int size = v.size();
    for (int i = 1; i < size; i++) {
        if (max_ending_here < 0) {
            max_ending_here = v[i];
        }
        else {
            max_ending_here += v[i];
        }

        max_so_far = max(max_ending_here, max_so_far);
    }
    return max_so_far;
}

void solve() {
    for (int r = 0; r < n; r++) {
        for (int c = 1; c <= n; c++) {
            acc[r][c] = acc[r][c-1] + in[r][c-1];
        }
    }

    int maxi = 0xF0000000;
    for (int from = 0; from < n; from++) {
        for (int to = from + 1; to <= n; to++) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(acc[i][to] - acc[i][from]);
            }
            maxi = max(maxi, max_subarray(v));
        }
    }
    printf("%d\n", maxi);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
