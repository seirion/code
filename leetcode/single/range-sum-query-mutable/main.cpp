// https://leetcode.com/problems/range-sum-query-mutable/
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        v.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        i++; // 1-based indexing

        int org = range(i) - range(i-1);
        int diff = val - org;

        while (i < v.size()) {
            v[i] += diff;
            i += -i&i;
        }
    }

    int sumRange(int i, int j) {
        return range(j+1) - range(i);
    }
private:
    int range(int to) { // [1, to]
        int sum = 0;
        while (0 < to) {
            sum += v[to];
            to -= -to&to;
        }
        return sum;
    }
private:
    vector<int> v;
};

int main() {
    // Your NumArray object will be instantiated and called as such:
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(1, 10);
    cout << numArray.sumRange(1, 2) << endl;
    return 0;
}
