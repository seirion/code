// http://codeforces.com/contest/509/problem/C
// C. Sums of Digits
#include <cstdio>
#include <deque>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
class Big {public: // BigNumber
    Big() : sum(0) {}
    deque<char> num;
    int sum;
    Big &operator =(const Big &b) {
        num = b.num; sum = b.sum;
        return *this;
    }
    void add(int s) {
        sum += s;
        int i;
        for (i = num.size() - 1; i >= 0; i--) {
            int t = 9 - num[i];
            if (s > t) {
                num[i] = 9; s -= t;
            }
            else {
                num[i] += s;
                return;
            }
        }

        for (;;) {
            if (s > 9) {
                num.push_front(9);
                s -= 9;
            }
            else {
                num.push_front(s);
                return;
            }
        }
    }
    void next(const Big &b, int s) {
        num.resize(b.num.size(), 0); sum = s;
        int i;
        for (i = 0; i < b.num.size(); i++) {
            if (s > b.num[i]) {
                num[i] = b.num[i];
                s -= b.num[i];
            }
            else {
                num[i] = s;
                break;
            }
        }
        for (; i >= 0; i++) {
            if (num[i] > 0) break;
        }
        num[i]--;
        i--;
        for (; i >= 0; i--) {
            if (num[i] < 9) break;
        }
        if (i < 0) {
            fill(num.begin(), num.end(), 0);
            num.push_front(1);
            int temp = sum - 1; sum = 1;
            add(temp);
        }
        else {
            num[i]++;
            deque<char>::iterator it = num.begin();
            advance(it, i+1);
            int temp = accumulate(it, num.end(), 0);
            fill(it, num.end(), 0);
            sum = sum - temp;
            add(temp);
        }
    }
    void swap(Big &b) {
        num.swap(b.num); sum = b.sum;
    }
    void print() const {
        for (int i = 0; i < num.size(); i++) { printf("%d", num[i]); }
        printf("\n");
    }
};
 
void get_next(Big &now, int sum) {
    Big next;
    if (now.sum < sum) {
        next = now;
        next.add(sum - now.sum);
    }
    else {
        next.next(now, sum);
    }
    now.swap(next);
}
 
int main() {
    int n;
    scanf("%d", &n);
    Big now;
    now.num.push_front(0);
    for (int i = 0; i < n; i++) {
        int sum;
        scanf("%d", &sum);
        get_next(now, sum);
        now.print();
    }
    return 0;
}
