#include <iostream>
#include <string>
using namespace std;


int maxLength(string& s) {
    int maxLen = 0;

    // Left to Right Traversal
    int open = 0, close = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            open++;
        } else if (s[i] == ')') {
            close++;
        }

        if (open == close) {
            maxLen = max(maxLen, 2 * close);
        } else if (close > open) {
            open = close = 0;
        }
    }

    // Right to Left Traversal
    open = close = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            open++;
        } else if (s[i] == ')') {
            close++;
        }

        if (open == close) {
            maxLen = max(maxLen, 2 * open);
        } else if (open > close) {
            open = close = 0;
        }
    }

    return maxLen;
}

int main() {
    string s = "(()())";
    cout << "Longest Valid Parentheses Length: " << maxLength(s) << endl;
    return 0;
}
