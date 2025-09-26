#include <iostream>
using namespace std;

void reverseString(string &s, int i, int j) {
    if (i >= j) return;  // base case
    swap(s[i], s[j]);
    reverseString(s, i + 1, j - 1);
}

int main() {
    string s = "recursion";
    reverseString(s, 0, s.size() - 1);
    cout << "Reversed string: " << s;
    return 0;
}
