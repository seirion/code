#include <iostream>
#include <set>
#include <string>

using namespace std;

int len, n;
string from[36];
char to[36];
set<string> s1, s2;

void put(string &now) {
    int size = now.size();
    char latter = now[0];
    for (int x = 0; x < n; x++) { // n ...
        if (latter == to[x]) {
            s2.insert(from[x] + now.substr(1, size-1));
        }
    }
}

int main() {
    cin >> len >> n;
    for (int i = 0; i < n; i++) {
        cin >> from[i] >> to[i];
    }

    s1.insert("a");
    for (int i = 2; i <= len; i++) {
        for (string str : s1) {
            put(str);
        }
        s1.swap(s2);
        s2.clear();
    }

    cout << s1.size() << endl;
    return 0;
}
