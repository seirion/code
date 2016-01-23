// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-21-generics
// Day 21: Generics!

#include <iostream>
#include <vector>

using namespace std;

template<class T>
void printArray(const vector<T> &v) {
    for (auto x : v) {
        cout << x << endl;
    }
}

int main() {
    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};

    printArray<int>(vInt);
    printArray<string>(vString);
    return 0;
}
