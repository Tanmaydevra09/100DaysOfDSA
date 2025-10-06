#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubsequences(int index, int sum, vector<int>& nums, int k) {
        // Base case: reached end of array
        if (index == nums.size()) {
            return (sum == k) ? 1 : 0;
        }

        // Include current element
        int include = countSubsequences(index + 1, sum + nums[index], nums, k);

        // Exclude current element
        int exclude = countSubsequences(index + 1, sum, nums, k);

        return include + exclude;
    }

    int countSubsequencesWithSumK(vector<int>& nums, int k) {
        return countSubsequences(0, 0, nums, k);
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {4, 9, 2, 5, 1};
    int k1 = 10;
    cout << "Count (Example 1): " << sol.countSubsequencesWithSumK(nums1, k1) << endl;

    vector<int> nums2 = {4, 2, 10, 5, 1, 3};
    int k2 = 5;
    cout << "Count (Example 2): " << sol.countSubsequencesWithSumK(nums2, k2) << endl;

    return 0;
}
