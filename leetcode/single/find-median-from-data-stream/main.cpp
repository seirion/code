// https://leetcode.com/problems/find-median-from-data-stream/
#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        tail.push(num);
        while (head.size() < tail.size()) {
            int x = tail.top(); tail.pop();
            head.push(x);
        }
        while (head.top() > tail.top()) {
            int x = head.top(); head.pop();
            int y = tail.top(); tail.pop();
            head.push(y);
            tail.push(x);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (head.size() == tail.size()) return (double)(head.top() + tail.top())/2;
        else return (double)head.top();
    }

private:
    priority_queue<int> head;
    priority_queue<int, vector<int>, greater<int> > tail;
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
