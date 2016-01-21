// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-19-interfaces
// Day 19: Interfaces!

#include <iostream>

using namespace std;

class AdvancedArithmetic{
public:
    virtual int divisorSum(int n)=0;
};

class Calculator : public AdvancedArithmetic {
public:
    virtual int divisorSum(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) sum += i;
        }
        return sum;
    }
};

int main(){
    int n;
    cin>>n;
    AdvancedArithmetic *myCalculator=new Calculator();
    int sum=myCalculator->divisorSum(n);
    cout<<"I implemented: AdvancedArithmetic\n"<<sum;
    return 0;
}
