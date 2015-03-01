// http://algospot.com/judge/problem/read/LUCKYNUM
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <deque>
#include <iterator>

using namespace std;

class BigNum { public:
    BigNum() {}
    BigNum(const char* in) {
        set(in);
    }
    BigNum &set(const char* in) {
        int size = strlen(in);
        for (int i = 0; i < size; i++) {
            v.push_back(in[i]);
        }
        return *this;
    }
    void push(int i) { v.push_back(i); }
    void clear() { v.clear(); }
    deque<char> v;
    BigNum operator -(const BigNum &bn) const {
        if (*this < bn) {
            return bn - *this;
        }

        BigNum ss;
        ss.v = v;

        if (bn.v.empty()) return ss;

        int aa(ss.v.size()-1), bb(bn.v.size()-1);
        for (; bb >= 0; aa--, bb--) {
            if (ss.v[aa] < bn.v[bb]) {
                ss.v[aa-1]--;
                ss.v[aa] += 10;
            }
            ss.v[aa] -= bn.v[bb];
        }
        while (!ss.v.empty() && ss.v.front() == 0) ss.v.pop_front();
        return ss;
    }
    bool operator <(const BigNum &bn) const {
        if (v.size() < bn.v.size()) return true;
        if (v.size() > bn.v.size()) return false;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != bn.v[i]) return v[i] < bn.v[i];
        }
        return false;
    }
    void print() const {
        for (int i = 0; i < v.size(); i++) printf("%d", v[i]);
        printf("\n");
    }
};

int k, size;
int in[10];
BigNum b;

void input() {
    b.clear();
    char buffer[204];
    gets(buffer);
    size = strlen(buffer) - 2; // space, k
    k = buffer[size + 1] - '0';
    for (int i = 0; i < size; i++) {
        b.push(buffer[i] - '0');
    }
}

void reset() {
    memset(in, 0, sizeof(int) * 10);
    for (int i = 0; i < size; i++) in[b.v[i]]++;
}

int get_min(int from) {
    for (int i = from + 1; i <= 9; i++) {
        if (in[i] > 0) {
            in[i]--;
            return i;
        }
    }
    return -1;
}

int get_max(int from) {
    for (int i = from - 1; i >= 0; i--) {
        if (in[i] > 0) {
            in[i]--;
            return i;
        }
    }
    return -1;
}

BigNum make_greater() {
    reset();
    BigNum ss;
    int remain = size;

    while (remain > 0) {
        if (in[k] > 0) {
            ss.push(k);
            in[k]--;
            remain--;
        }
        else {
            int temp = get_min(k);
            if (temp == -1) {
                ss.v.clear();
                return ss;
            }
            ss.push(temp);
            remain--;
            break;
        }
    }

    for (int i = 0; i <= 9; i++) {
        while (in[i] > 0) {
            ss.push(i);
            in[i]--;
        }
    }
    return ss;
}

BigNum make_less() {
    reset();
    BigNum ss;
    int remain = size;

    while (remain > 0) {
        if (in[k] > 0) {
            ss.push(k);
            in[k]--;
            remain--;
        }
        else {
            int temp = get_max(k);
            if (temp == -1) {
                ss.v.clear();
                return ss;
            }
            ss.push(temp);
            remain--;
            break;
        }
    }

    for (int i = 9; i >= 0; i--) {
        while (in[i] > 0) {
            ss.push(i);
            in[i]--;
        }
    }
    return ss;
}

void solve() {
    BigNum gg = make_greater();
    BigNum ll = make_less();

    BigNum lucky;
    for (int i = 0; i < size; i++) lucky.v.push_back(k);
    BigNum xx = gg-lucky;
    BigNum yy = ll-lucky;

    if (yy < xx) {
        ll.print();
    }
    else {
        gg.print();
    }
}

int main() {
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
