// https://leetcode.com/problems/next-permutation/solution/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // finding first decreasing element from the last
        int i;
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) break;
        }

        if (i == -1) { // all decreasing order
            reverse(nums.begin(), nums.end());
            return;
        }
        int one = i++;

        // finding number lager than nums[one]
        for (; i < nums.size(); i++) {
            if (nums[one] >= nums[i]) break;
        }
        int two = i - 1;

        // swap
        swap(nums[one], nums[two]);

        // reverse
        auto it = nums.begin();
        advance(it, one + 1);
        reverse(it, nums.end());
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int> org = v;
    do {
        for (auto i : v) cout << i << " "; cout << endl;
        Solution().nextPermutation(v);
    } while (v != org);
}
