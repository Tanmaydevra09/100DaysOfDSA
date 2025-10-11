#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recurPermute(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, vector<int>& used) {
    if (temp.size() == nums.size()) {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

        used[i] = 1;
        temp.push_back(nums[i]);
        recurPermute(nums, temp, res, used);
        temp.pop_back();
        used[i] = 0;
    }
}

int main() {
    vector<int> nums = {1, 1, 2};
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<int> temp, used(nums.size(), 0);

    recurPermute(nums, temp, res, used);

    cout << "Unique permutations are:" << endl;
    for (auto &v : res) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}
