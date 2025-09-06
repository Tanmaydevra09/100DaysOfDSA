#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int B) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // Base case: empty prefix

        int count = 0, prefix = 0;

        for (int num : arr) {
            prefix ^= num; // Update prefix XOR

            // Check if prefix^B exists in map
            if (mp.find(prefix ^ B) != mp.end()) {
                count += mp[prefix ^ B];
            }

            // Store/update prefix frequency
            mp[prefix]++;
        }

        return count;
    }
};

// Example run
int main() {
    Solution sol;
    vector<int> arr = {4, 2, 2, 6, 4};
    int B = 6;
    cout << "Number of subarrays with XOR " << B << " = "
         << sol.solve(arr, B) << endl;
    return 0;
}
