// http://algospot.com/judge/problem/read/RUNNINGMEDIAN
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef unsigned long long int64;
const int64 DEVIDER = 20090711LL;
int64 n, a, b;

void getInput() {
    cin >> n >> a >> b;
}

void solve() {
    int64 sum = 1983;
    int temp = (1983 * a + b) % DEVIDER;
    priority_queue<int64> minor; // lesser parts
    priority_queue<int64, std::vector<int64>, std::greater<int64> > major; // greater parts

    minor.push(min(1983, temp)); // initial conditions
    major.push(max(1983, temp));
    sum += minor.top();

    for (int i = 3; i <= n; i++) {
        temp = (temp * a + b) % DEVIDER;
        if (i % 2 == 1) minor.push(temp);
        else major.push(temp);

        if (minor.top() > major.top()) { // swap
            major.push(minor.top());
            minor.push(major.top());
            major.pop();
            minor.pop();
        }
        sum += minor.top();
    }
    cout << sum % DEVIDER << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
