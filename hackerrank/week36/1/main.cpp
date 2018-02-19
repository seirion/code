#include <iostream>
#include <string>

using namespace std;

bool starts(const string &src, const string &pat) {
    auto a = src.begin();
    auto b = pat.begin();
    while (a != src.end() && b != pat.end()) {
        if (*a != *b) return false;
        a++; b++;
    }
    return b == pat.end();
}

bool ends(const string &src, const string &pat) {
    auto a = src.rbegin();
    auto b = pat.rbegin();
    while (a != src.rend() && b != pat.rend()) {
        if (*a != *b) return false;
        a++; b++;
    }
    return b == pat.rend();
}

string go(const string& s) {
    if (ends(s, "ic")) {
        if (starts(s, "hydro")) return "non-metal acid";
        else return "polyatomic acid";
    }
    return "not an acid";
}

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        cout << go(s) << endl;
    }
    return 0;
}
