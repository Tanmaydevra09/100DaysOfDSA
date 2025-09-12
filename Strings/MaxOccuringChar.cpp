#include <iostream>
#include <string>
using namespace std;

// Function to find the maximum occurring character in a string
char getMaxOccuringChar(string& s) {
    int count[256] = {0};

    // Count frequency of each character
    for (int i = 0; i < s.size(); i++) {
        count[s[i]]++;
    }

    char res = s[0];
    int freq = 0;

    // Find character with max frequency (lexicographically smaller in tie)
    for (int i = 0; i < s.size(); i++) {
        if (count[s[i]] > freq) {
            freq = count[s[i]];
            res = s[i];
        } else if (count[s[i]] == freq) {
            if (s[i] < res) {
                res = s[i];
            }
        }
    }

    return res;
}

int main() {
    string s = "testsample";
    cout << "Max occurring character: " << getMaxOccuringChar(s) << endl;
    return 0;
}
