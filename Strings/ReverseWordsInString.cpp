#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverseStr(string &s, int low, int high) {
    while (low <= high) {
        swap(s[low], s[high]);
        low++;
        high--;
    }
}

void reverseWords(string &s) {
    int n = s.size();
    int start = 0;

    // reverse each word individually
    for (int end = 0; end < n; end++) {
        if (s[end] == ' ') {
            reverseStr(s, start, end - 1);
            start = end + 1;
        }
    }

    // reverse last word
    reverseStr(s, start, n - 1);

    // reverse entire string
    reverseStr(s, 0, n - 1);
}

int main() {
    string s = "Welcome to Gfg";

    cout << "After reversing words in the string:" << endl;
    reverseWords(s);
    cout << s << endl;   // Output: Gfg to Welcome

    return 0;
}
