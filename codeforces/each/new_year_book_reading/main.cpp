// http://codeforces.com/problemset/problem/500/C
// C. New Year Book Reading
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<int> w, d;
list<int> order;
bool checked[501] = {false,};

int read(int index) {
    int sum = 0;
    list<int>::iterator i = order.begin();
    for (; i != order.end(); i++) {
        if (*i == index) {
            order.erase(i);
            order.push_front(index);
            return sum;
        }
        sum += w[*i-1];
    }
    return 0; // something wrong
}

int min_weight() {
    int weight = 0;
    for (int i = 0; i < d.size(); i++) {
        weight += read(d[i]);
    }
    return weight;
}

int main() {
    int i, num, day;
    scanf("%d %d", &num, &day);

    for (i = 0; i < num; i++) {
        int temp;
        scanf("%d", &temp);
        w.push_back(temp);
    }
    for (i = 0; i < day; i++) {
        int temp;
        scanf("%d", &temp);
        d.push_back(temp);
        if (!checked[temp]) {
            checked[temp] = true;
            order.push_back(temp);
        }
    }

    printf("%d\n", min_weight());
    return 0;
}
