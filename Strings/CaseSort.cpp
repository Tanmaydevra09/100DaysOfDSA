// Day 19: Case-Specific Sorting of a String — C++

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to sort a string such that uppercase and lowercase
    // letters maintain their original positions, but are sorted
    // within their respective groups.
    string caseSort(string s, int n) {
        string lowercase, uppercase;

        // Step 1: Separate lowercase and uppercase letters
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                lowercase.push_back(s[i]);
            } else {
                uppercase.push_back(s[i]);
            }
        }

        // Step 2: Sort both groups individually
        sort(lowercase.begin(), lowercase.end());
        sort(uppercase.begin(), uppercase.end());

        // Step 3: Merge them back while preserving case positions
        string result;
        int li = 0, ui = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                result.push_back(lowercase[li++]);
            } else {
                result.push_back(uppercase[ui++]);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "defRTSersUXI";
    int n = s.length();

    string sortedString = sol.caseSort(s, n);
    cout << "Case-Specific Sorted String: " << sortedString << endl;
    // Example Output: deeIRSfrsTUX

    return 0;
}
