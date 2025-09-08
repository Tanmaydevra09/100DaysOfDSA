#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate factorial
    long long fac(int n) {
        long long fa = 1;
        for (int i = 1; i <= n; i++) {
            fa *= i;
        }
        return fa;
    }

    // Function to find lexicographic rank of a string
    int findRank(string S) {
        int res = 1;
        int n = S.length();
        long long mul = fac(n);

        int count[256] = {0};

        // Count frequency of each character
        for (int i = 0; i < n; i++) {
            count[S[i]]++;
        }

        // Convert to cumulative count
        for (int i = 1; i < 256; i++) {
            count[i] += count[i - 1];
        }

        // Calculate rank
        for (int i = 0; i < n - 1; i++) {
            mul = mul / (n - i);
            res = res + (count[S[i] - 1]) * mul;

            // Reduce count of characters after fixing S[i]
            for (int j = S[i]; j < 256; j++) {
                count[j]--;
            }
        }

        return res % 1000000007;
    }
};

int main() {
    Solution sol;
    string S = "STRING";
    cout << "Lexicographic Rank of " << S << " is: " << sol.findRank(S) << endl;
    return 0;
}
