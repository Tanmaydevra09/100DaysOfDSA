#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int res = nums[0];

        // Boyer-Moore Voting Algorithm
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == res) {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                res = nums[i];
                count = 1;
            }
        }

        // Verify candidate
        count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == res) {
                count++;
            }
        }

        if (count > nums.size() / 2) {
            return res;
        }
        return -1; // No majority element
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << s.majorityElement(nums) << endl;
    return 0;
}
