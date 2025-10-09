#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target becomes 0, store the current combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // If index exceeds or target becomes negative, return
        if (index == candidates.size() || target < 0) return;

        // Include the current element
        current.push_back(candidates[index]);
        findCombinations(index, target - candidates[index], candidates, current, result);
        current.pop_back();

        // Exclude the current element and move forward
        findCombinations(index + 1, target, candidates, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (auto comb : ans) {
        cout << "[ ";
        for (auto num : comb) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
