// http://algospot.com/judge/problem/read/ITES
#include <iostream>
#include <deque>

using namespace std;

typedef unsigned int uint32;

uint32 k, n;

void getInput() {
    cin >> k >> n;
}

void solve() {
    uint32 current = 1983;
    deque<uint32> q;
    q.push_back(current+1);
    uint32 sum = q.back();
    uint32 count = 0;

    for (int i = 1; i <= n; i++) {
        current = current * 214013 + 2531011;
        q.push_back(current % 10000 +1);
        sum += q.back();

        while(!q.empty() && sum > k) {
            sum -= q[0];
            q.pop_front();
        }
        if (sum == k) count++;
    }
    cout << count << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
