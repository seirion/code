#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

class T { public:
    T() : i(0) {}
    int i; // next index
    set<int> r; // remain
    int put() {
        if (r.empty()) {
            int prev = i;
            i++;
            return prev;
        } else {
            int res = *r.begin();
            r.erase(r.begin());
            return res;
        }
    }
    void del(int x) {
        if (x == i-1) {
            i--;
            while (!r.empty()) {
                auto it = r.end(); it--;
                if (*it == i-1) {
                    r.erase(it);
                    i--;
                } else break;
            }
        } else {
            r.insert(x);
        }
    }
};

map<string, T> m;

int crt(string & str) {
    auto &t = m[str];
    return t.put();
}

int num(string &str) {
    if (str.back() != ')') return 0;

    int x(0), tens(1);
    str.pop_back();
    while (str.back() != '(') {
        x = (str.back() - '0') * tens + x;
        str.pop_back();
        tens *= 10;
    }
    str.pop_back();
    return x;
}

void del(string& str) {
    int x = num(str);
    auto &t = m[str];
    return t.del(x);
}

void out(int x) {
    if (x == 0) {
        cout << endl;
    } else {
        cout << "(" << x << ")" << endl;
    }
}

int main() {
    int n; cin >> n;
    string c, str; // command, name

    while (n--) {
        cin >> c;
        switch (c[0]) {
            case 'c': // crt
                cin >> str;
                cout << "+ " << str; out(crt(str));
                break;
            case 'd': // del
                cin >> str;
                cout << "- " << str << endl;
                del(str);
                break;
            case 'r': // rnm
                cin >> str;
                cout << "r " << str << " -> ";
                del(str);
                cin >> str;
                cout << str; out(crt(str));
                break;
        }
    }
    return 0;
}
