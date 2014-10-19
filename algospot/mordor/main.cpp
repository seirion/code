// http://algospot.com/judge/problem/read/MORDOR
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int min_[1 << 18]; // 262,144
int max_[1 << 18]; // 262,144

void make_min_max_tree(int size) {
    for (int i = size - 2; i >= 0; i--) {
        // left : i * 2 - 1; right : i * 2;
        min_[i] = min(min_[i*2+1], min_[(i+1)*2]);
        max_[i] = max(max_[i*2+1], max_[(i+1)*2]);
    }
}

int get_max(int root, int start, int end, int from, int to) {
    if (start == from && end == to) return max_[root];
    int maxi = -1;
    int mid = (end + start) / 2;
    if (from <= mid) {
        maxi = get_max(root*2+1, start, mid, from, min(mid, to));
    }
    if (mid < to) {
        maxi = max(maxi, get_max((root+1)*2, mid+1, end, max(mid+1, from), to));
    }
    return maxi;
}

int get_min(int root, int start, int end, int from, int to) {
    if (start == from && end == to) return min_[root];
    int maxi = 0x7FFFFFFF;
    int mid = (end + start) / 2;
    if (from <= mid) {
        maxi = get_min(root*2+1, start, mid, from, min(mid, to));
    }
    if (mid < to) {
        maxi = min(maxi, get_min((root+1)*2, mid+1, end, max(mid+1, from), to));
    }
    return maxi;
}

void solve() {
    int i, N, Q, size, from, to;
    scanf("%d %d", &N, &Q);
    memset(min_, 0x7F, sizeof(int) * (1<<18));
    memset(max_, 0xFF, sizeof(int) * (1<<18));

    size = 1;
    while (N > size) {
        size <<= 1;
    }

    for (i = 0; i < N; i++) {
        scanf("%d", &min_[size-1+i]);
        max_[size-1+i] = min_[size-1+i];
    }

    make_min_max_tree(size);
    for (i = 0; i < Q; i++) {
        scanf("%d %d", &from, &to);
        printf("%d\n", get_max(0, 0, size-1, from, to) - get_min(0, 0, size-1, from, to));
    }
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve();}
    return 0;
}
