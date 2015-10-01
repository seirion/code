// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/feighbours
#include <iostream>
#include <vector>

using namespace std;

int in[50001];

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b); 
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];

    for (int a = 0; a < n; a++) {
        int index = -1;
        for (int b = a+1; b < n; b++) {
            //printf("%d %d %d\n", in[a], in[b], gcd(in[a],in[b]));
            if (gcd(in[a], in[b]) != 1) {
                index = b+1;
                break;
            }
        }

        cout << index << " ";
    }
    cout << endl;

}
