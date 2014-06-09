// http://algospot.com/judge/problem/read/NOTE
#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    char b[64] = {0, };
    gets(b);
    if (b[0] == '1' && b[2] == '2' && b[4] == '3' && b[6] == '4' &&
            b[8] == '5' && b[10] == '6' && b[12] == '7' && b[14] == '8') {
        cout << "ascending" << endl;
    }
    else if (b[0] == '8' && b[2] == '7' && b[4] == '6' && b[6] == '5' &&
            b[8] == '4' && b[10] == '3' && b[12] == '2' && b[14] == '1') {
        cout << "descending" << endl;
    }
    else {
        cout << "mixed" << endl;
    }

    return 0;
}
