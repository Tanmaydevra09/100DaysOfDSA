#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (1 << nums.size()); // total subsets = 2^n
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < nums.size(); j++) {
                if ((i & (1 << j)) != 0) { // check if jth bit is set
                    v.push_back(nums[j]);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.subsets(nums);

    cout << "All subsets:\n";
    for (auto subset : ans) {
        cout << "{ ";
        for (auto x : subset) cout << x << " ";
        cout << "}\n";
    }
    return 0;
}
