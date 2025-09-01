#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        // Sort intervals based on starting times
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Merge overlapping intervals
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                j++;
            }

            // Update index and store merged interval
            i = j - 1;
            res.push_back({start, end});
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = sol.merge(intervals);

    cout << "Merged Intervals: ";
    for (auto &interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
