// https://www.hackerrank.com/challenges/kaprekar-numbers
// Modified Kaprekar Numbers
#include <iostream>
#include <vector>

using namespace std;

bool kaprekar_numbers(long long x) {
    vector<long long> right, left;
    long long square = x * x;
    do {
        left.push_back(square);
        square /= 10;
    }
    while (0 < square);
    left.push_back(0);

    square = x * x;
    long long dev = 1;
    for (int i = 0; i < left.size(); i++, dev *= 10) {
        right.push_back(square % dev);
    }

    int size = left.size();
    return (left[size/2] + right[size/2]) == x;
}

int main() {
    long long from, to;
    cin >> from >> to;

    vector<long long> res;
    for (int i = from; i <= to; i++) {
        if (kaprekar_numbers(i)) res.push_back(i);
    }

    if (res.empty()) {
        cout << "INVALID RANGE\n";
    }
    else {
        for (auto x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}
