#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;              // maximum profit
        int minPrice = prices[0]; // minimum price so far

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i]; // update min price 
            }
            res = max(res, prices[i] - minPrice); // update max profit
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
