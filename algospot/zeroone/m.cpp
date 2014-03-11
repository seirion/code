// http://algospot.com/judge/problem/read/ZEROONE
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<char> in;

void getInput() {
    char *c = new char [100000];
    cin.getline(c, 100000);
    size_t s = strlen(c);
    for (int i = 0; i < 100000; i++) {
        in.push_back(c[i%8] == '1');
    }
    /*
    for (int i = 0; i < s; i++) {
        in.push_back(c[i] == '1');
    }
    */
    delete [] c;
}

void solve() {
    int from, to;
    cin >> from >> to;
    bool b = in[from];
    int i;
    for (i = 0; i < 100000; i++) { // test
        bool a = (in[i] == 1);
    }
    cout << i << endl;
    /*
    for (int i = from + 1; i <= to; i++) {
        if (in[i] != b) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    */
}

int main() {
    getInput();
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
