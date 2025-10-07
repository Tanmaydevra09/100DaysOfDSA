#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findSubsetSums(int index, int currentSum, vector<int>& nums, vector<int>& result) {
        // Base case: reached end of array
        if (index == nums.size()) {
            result.push_back(currentSum);
            return;
        }

        // Include current element in subset
        findSubsetSums(index + 1, currentSum + nums[index], nums, result);

        // Exclude current element from subset
        findSubsetSums(index + 1, currentSum, nums, result);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> result;
        findSubsetSums(0, 0, nums, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3};
    
    vector<int> res = sol.subsetSums(nums);

    cout << "Subset sums: ";
    for (int sum : res) cout << sum << " ";
    cout << endl;

    return 0;
}
