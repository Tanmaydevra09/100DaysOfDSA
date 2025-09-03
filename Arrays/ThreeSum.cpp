// Day 6: Add 3Sum (Arrays) — C++
// Problem: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
         
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // skip duplicates
            }
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "Triplets summing to 0 are:\n";
    for (auto& triplet : ans) {
        cout << "[ ";
        for (int x : triplet) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
