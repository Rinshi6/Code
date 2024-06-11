#include <bits/stdc++.h>
using namespace std;

int countValidSubstrings(string s) {
    int n = s.length();
    vector<int> dp(n + 1, 0);

    // Base case: dp[0] = 0
    dp[0] = 0;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        // Initialize dp[i] with dp[i-1] as we can always add 'a' as a separate substring
        dp[i] = dp[i - 1] + 1;

        // Check for valid substrings
        for (int j = 1; j <= i - 1; j++) {
            if (s.substr(i - j, j) != "a" && s.substr(i - j, j) == s.substr(i - 2 * j, j)) {
                // If the substring is not 'a' and is equal to the previous substring, update dp[i]
                dp[i] -= dp[i - j - 1];
                break;
            }
        }
    }

    // Return the count of valid substrings for the entire string s
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << countValidSubstrings(s) << endl;
    }
    return 0;
}
