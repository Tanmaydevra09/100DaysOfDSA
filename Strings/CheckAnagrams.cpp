#include <iostream>
#include <string>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagrams(string& s1, string& s2) {
    // If lengths differ, they can’t be anagrams
    if (s1.length() != s2.length()) return false;

    int freq[26] = {0};

    // Count frequency for s1
    for (char c : s1) {
        if (c >= 'A' && c <= 'Z')
            freq[c - 'A']++;
        else
            freq[c - 'a']++;
    }

    // Subtract frequency for s2
    for (char c : s2) {
        if (c >= 'A' && c <= 'Z')
            freq[c - 'A']--;
        else
            freq[c - 'a']--;
    }

    // If any count is not zero, not an anagram
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}

int main() {
    string s1 = "Listen";
    string s2 = "Silent";

    if (areAnagrams(s1, s2))
        cout << s1 << " and " << s2 << " are anagrams." << endl;
    else
        cout << s1 << " and " << s2 << " are NOT anagrams." << endl;

    return 0;
}
