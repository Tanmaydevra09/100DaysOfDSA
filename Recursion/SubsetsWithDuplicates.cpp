#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recurSubset(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res) {
    res.push_back(temp);

    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates
        if (i > index && nums[i] == nums[i - 1]) continue;

        temp.push_back(nums[i]);
        recurSubset(i + 1, nums, temp, res);
        temp.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 2};
    sort(nums.begin(), nums.end()); // Important for skipping duplicates

    vector<vector<int>> res;
    vector<int> temp;

    recurSubset(0, nums, temp, res);

    cout << "Unique subsets are:" << endl;
    for (auto &subset : res) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}
