#include <iostream>

using namespace std;

long long s, e, duration, n;

long long best = 12345678912345L;
long long bestPoint = -1;

long long finish = 0;
long long now = 0;

void check(long long x) {
        now = x - 1;
        if (e <= now) {
            finish = e + duration;
            return;
        }

        if (finish <= now && finish + duration <= e) {
            best = 0;
            bestPoint = finish;
            return;
        }

        if (finish - now < best && finish + duration <= e) {
            best = finish - now;
            bestPoint = now;
        }

        if (x <= finish) finish += duration;
        else finish = x + duration;
}

int main() {
    cin >> s >> e >> duration >> n;
    finish = s;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
            
        if (x == 0) {
            finish += duration;
            continue;
        }

        check(x);
        if (best == 0) goto OUT;
        if (e <= finish) break;
    }
    if (finish < e) check(e);
    else if (bestPoint == -1) {
        if (s + duration <= e) bestPoint = s;
        else bestPoint = e - duration;
    }

OUT:
    cout << bestPoint << endl;
    return 0;
}

