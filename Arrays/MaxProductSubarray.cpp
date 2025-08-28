#include <iostream>
#include <vector>
#include <algorithm> // for min, max, swap
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ele = nums[0];
        int min_ele = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(min_ele, max_ele);

            min_ele = min(nums[i], min_ele * nums[i]);
            max_ele = max(nums[i], max_ele * nums[i]);
            res = max(res, max_ele);
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 3, -2, 4};

    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl;

    return 0;
}
