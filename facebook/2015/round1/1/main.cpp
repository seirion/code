// https://www.facebook.com/hackercup/problems.php?pid=582396081891255&round=344496159068801
// Facebook Hacker Cup 2015 Round 1
// 1. Homework
#include <cstdio>
#include <vector>

using namespace std;

const int LIMIT = 10000000;
vector<int> prime;
int nprime[LIMIT + 1];


bool is_prime(int p) {
    for (int i = 0; i < prime.size(); i++) {
        if (p % prime[i] == 0) return false;
    }
    return true;
}

int prime_num(int p) {
    int org = p;
    for (int i = 0; i < prime.size(); i++) {
        while (p % prime[i] == 0) {
            p /= prime[i];
        }
        if (org != p) {
            return 1 + nprime[p];
        }
    }
    return 1;
}

int make_prime() {
    prime.push_back(2);
    int i;
    for (i = 3; i <= 3163; i++) {
        if (is_prime(i)) prime.push_back(i);
    }

    nprime[0] = nprime[1] = 0;
    for (i = 2; i <= LIMIT; i++) {
        nprime[i] = prime_num(i);
    }
}

void solve() {
    int A, B, K;
    scanf("%d %d %d", &A, &B, &K);
    int c(0);
    for (int i = A; i <= B; i++) {
        if (nprime[i] == K) c++;
    }
	printf("%d\n", c);
}

int main() {
    make_prime();
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

