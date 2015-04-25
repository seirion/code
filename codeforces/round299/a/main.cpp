// http://codeforces.com/contest/535/problem/A
// A. Tavas and Nafas
#include <iostream>

using namespace std;

const char *one[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char *ten[] = {
    "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

int main() {
    int a;
    cin >> a;

    if (a < 20) {
        cout << one[a] << endl;
    }
    else if (a % 10 == 0) {
        cout << ten[a/10] << endl;
    }
    else {
        cout << ten[a/10] << "-" << one[a%10] << endl;
    }
    return 0;
}
