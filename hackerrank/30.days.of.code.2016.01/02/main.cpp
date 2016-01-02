// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-2-arithmetic
// Day 2: Arithmetic!

#include <iostream>

using namespace std;

int main() {
    double price;
    int tip, tax; // percentage
    cin >> price >> tip >> tax;

    cout << "The final price of the meal is $"
         << (int)(price + (price * tip / 100) + (price * tax / 100) + 0.5)
         << ".\n";

    return 0;
}
