// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-14-scope-and-imports
// Day 14: All about Scope!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Difference {
private:
    vector<int> elements;

public:
    int maximumDifference;

public:
    Difference(const vector<int> &e) : elements(e) {}
    void computeDifference() {
        maximumDifference = 
            *max_element(elements.begin(), elements.end()) -  
            *min_element(elements.begin(), elements.end());
    }
};


int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
