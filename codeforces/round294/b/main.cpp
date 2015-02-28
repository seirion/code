// http://codeforces.com/contest/519/problem/B
// B. A and B and Compilation Errors
#include <cstdio>
#include <set>


using namespace std;

int main() {
    int n, temp;
    scanf("%d", &n);
    multiset<int> s1, s2;
    std::multiset<int>::iterator it;

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        s1.insert(temp);
    }
    n--;

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        it = s1.find(temp);
        s1.erase(it);
        s2.insert(temp);
    }
    printf("%d\n", *s1.begin());
    n--;

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        it = s2.find(temp);
        s2.erase(it);
        s1.insert(temp);
    }
    printf("%d\n", *s2.begin());
    return 0;
}
