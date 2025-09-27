#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void recur(vector<string> &res, string s, int n, int open, int close) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }

        if (open < n) {
            recur(res, s + '(', n, open + 1, close);
        }
        if (close < open) {
            recur(res, s + ')', n, open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recur(res, "", n, 0, 0);
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> result = sol.generateParenthesis(n);
    cout << "Valid Parentheses combinations:\n";
    for (auto &str : result) {
        cout << str << endl;
    }

    return 0;
}
