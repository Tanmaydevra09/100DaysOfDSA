#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        backtrack(candidates, target, 0, path, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            if (candidates[i] > target) break;  // Prune
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, path, result); // i+1 because each number used once
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);

    cout << "Combinations are:\n";
    for (auto &comb : ans) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
