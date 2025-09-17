// Day 18: Check if Two Strings are Rotations of Each Other — C++

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if s2 is a rotation of s1
    bool areRotations(string &s1, string &s2) {
        // Step 1: If lengths differ, they cannot be rotations
        if (s1.length() != s2.length()) {
            return false;
        }

        // Step 2: Concatenate s1 with itself
        // Example: s1 = "ABCD", s1+s1 = "ABCDABCD"
        // Now, if s2 is a rotation, it must be a substring of s1+s1
        string temp = s1 + s1;

        // Step 3: Check if s2 exists inside temp
        if (temp.find(s2) != string::npos) {
            return true; // Found, so s2 is a rotation
        }

        // Step 4: Otherwise, it's not a rotation
        return false;
    }
};

int main() {
    Solution sol;

    string s1 = "ABCD";
    string s2 = "CDAB";

    if (sol.areRotations(s1, s2)) {
        cout << s2 << " is a rotation of " << s1 << endl;
    } else {
        cout << s2 << " is NOT a rotation of " << s1 << endl;
    }

    return 0;
}
