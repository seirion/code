// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-17-exceptions
// Day 17: Exceptions!

#include <iostream>
#include <cstdio>
#include <exception>

using namespace std;

class PowerException : public exception {
    virtual const char* what() const throw() {
        return "n and p should be non-negative";
    }
};

class Calculator {
public:
    Calculator() {}
    int power(int n, int p) {
        if (n < 0 || p < 0) {
            throw PowerException();
        }

        if (p == 0) return 1;
        if (p == 1) return n;
        int result = power(n, p/2);
        result *= result;
        if (p & 1) result *= n;
        return result;
    }
};

int main() {
    Calculator myCalculator = Calculator();
    int T, n, p;
    cin >> T;
    while (T-->0) {
        if (scanf("%d %d",&n,&p) == 2) {
            try {
                int ans = myCalculator.power(n, p);
                cout << ans << endl; 
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
        }
    }
    return 0;
}
