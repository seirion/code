#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;


char *_str;

bool check() {
    cin >> _str;
    size_t size = strlen(_str);

    vector<char> brackets;
    for (int i = 0; i < size; i++) {
        char c = _str[i];
        if (c == '(' || c == '{' || c == '[') {
            brackets.push_back(c);
        }
        else {
            if (brackets.empty()) return false;
            char back = brackets.back();
            //cout << back << " ";
            switch (back) {
                case '(': 
                    if (c != ')') return false;
                    brackets.pop_back();
                    break;
                case '{':
                    if (c != '}') return false;
                    brackets.pop_back();
                    break;
                case '[':
                    if (c != ']') return false;
                    brackets.pop_back();
                    break;
                default: break;
            }
        }
    }
    return brackets.empty();
}

int main() {
    int num;
    cin >> num;

    _str = new char[10001];
    for (int i = 0; i < num; i++) {
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    delete [] _str;
    return 0;
}
