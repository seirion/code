// http://algospot.com/judge/problem/read/WILDCARD
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string str;
vector<string> in;
vector<string> solution;


void getInput() {
    solution.clear();
    in.clear();

    getline(std::cin, str);
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
        char buffer[200];
        gets(buffer);
        in.push_back(string(buffer));    
    }
}

bool state(const string &testCase, int testIndex, int inIndex) {
    if (testIndex != testCase.size() && str.size() == inIndex) return false;
    if (testIndex == testCase.size()) {
        if (inIndex == str.size()) return true;
        if (str[inIndex] == '*') {
            return state(testCase, testIndex, inIndex + 1);
        }
        return false;
    }

    char t = testCase[testIndex];
    char ic = str[inIndex];

    if (ic == '?') {
        return state(testCase, testIndex + 1, inIndex + 1);
    }
    else if (ic == '*') {
        for (int i = testIndex; i <= testCase.size(); i++) {
            if (state(testCase, i, inIndex + 1)) {
                return true;
            }
        }
    }
    else {
        if (testCase[testIndex] != str[inIndex]) {
            return false;
        }
        else {
            return state(testCase, testIndex + 1, inIndex + 1);
        }
    }

    return false;
}

void solve() {
    size_t size = in.size();
    for (int i = 0; i < size; i++) {
        if (state(in[i], 0, 0)) {
            solution.push_back(in[i]);
        }
    }

    // print
    sort(solution.begin(), solution.end());
    for (vector<string>::const_iterator i = solution.begin(); i != solution.end(); i++) {
        cout << *i << endl;
    }
}

int main() {
    int num;
    cin >> num;
    cin.get();
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
