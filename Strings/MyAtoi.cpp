// Day 17: String to Integer (Atoi) — C++

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int recur(string &s, int i, long int res, int sign) {
        if (i < s.length()) {
            if (s[i] < '0' || s[i] > '9')
                return (int)(res * sign);
            else {
                res = res * 10 + (s[i] - '0');
                if (res * sign > INT_MAX) {
                    return INT_MAX;
                }
                if (res * sign < INT_MIN) {
                    return INT_MIN;
                }
            }
            return recur(s, i + 1, res, sign);
        }
        return (int)(res * sign);
    }

    int myAtoi(string s) {
        int sign = 1;
        int i = 0;

        // Skip whitespaces
        while (i < s.length() && s[i] == ' ')
            i++;

        // Handle sign
        if (i < s.length() && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < s.length() && s[i] == '+') {
            sign = 1;
            i++;
        }

        long res = 0;
        res = recur(s, i, res, sign);
        return (int)res;
    }
};

int main() {
    Solution sol;
    string s = "   -42";
    cout << "Converted integer: " << sol.myAtoi(s) << endl;
    return 0;
}
