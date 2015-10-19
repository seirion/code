// https://leetcode.com/problems/find-median-from-data-stream/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MedianFinder {
public:
    void addNum(int num) {
        v.push_back(num); 
        sort(v.begin(), v.end());
    }

    double findMedian() {
        if (v.size() & 1) return (double)v[v.size()/2];
        else return (double)(v[v.size()/2] + v[v.size()/2-1])/2;
    }
private:
    vector<int> v;
};

int main() {
    MedianFinder m;
    int n; cin >> n;
    int x; cin >> x; m.addNum(x);
    while (n--) {
        cin >> x;
        m.addNum(x);
        cout << m.findMedian() << endl;
    }

    return 0;
}
