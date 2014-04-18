// http://algospot.com/judge/problem/read/DARPA
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

int N, M;
list<int> in;

void getInput() {
    in.clear();
    double temp;
    int before, current;
    cin >> N >> M;
    cin >> temp;
    before = (int)(temp * 100);
    M--;
    in.push_back(30000);
    for (int i = 0; i < M; i++) {
        cin >> temp;
        current = (int)(temp * 100);
        in.push_back(current - before);
        before = current;
    }
}

void solve() {
    while (in.size() > N) {
        list<int>::iterator minIt, a, b;
        a = in.begin();
        b = in.begin();
        minIt = in.begin();
        b++;
        int minValue = *a;
        int minSum = (*a) + (*b);

        for (; b != in.end(); a++, b++) {
            if ((minValue > *b) || (minValue == *b && minSum > ((*a) + (*b)))) {
                minIt = a;
                minValue = *a;
                minSum = (*a) + (*b);
            }
        }

        minIt = in.erase(minIt);
        *minIt = minSum;
    }

    int mm = 0xFFFFFFF;
    list<int>::const_iterator it = in.begin();
    for (; it != in.end(); it++) {
        mm = min(mm, *it);
    }
    printf("%d.%02d\n", mm / 100, mm % 100);
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
