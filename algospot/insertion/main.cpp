// http://algospot.com/judge/problem/read/INSERTION
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int n;
int in[50000];
int temp[50000];
int res[50000];


void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        temp[i] = i + 1;
    }
}

int find(int count, int size) {
    int index = size - count;
    int result = temp[index];
    memmove(temp+index, temp+index+1, sizeof(int) * count);
    return result;
}

void solve() {
    int i;
    for (i = n-1; i >= 0; i--) {
        res[i] = find(in[i], i);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
