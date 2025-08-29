// Arrays/MaxSubarray.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int res = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            res = max(nums[i], res + nums[i]);
            max_sum = max(max_sum, res);
        }
        return max_sum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout << "Maximum Subarray Sum = " << sol.maxSubArray(nums) << endl;
    return 0;
}
