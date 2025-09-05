// Day 9: Sort Colors (Arrays) — C++

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int res = 0;

        // First pass: move all 0s to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[res]);
                res++;
            }
        }

        // Second pass: move all 1s after 0s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[res]);
                res++;
            }
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);

    cout << "Sorted Colors: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
