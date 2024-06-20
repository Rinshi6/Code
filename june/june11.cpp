#include <iostream>
#include <vector>

using namespace std;

// Function to find the optimal value of x for given n
int findOptimalX(int n) {
    int maxSum = 0;
    int optimalX = 2;

    // Iterate through all possible values of x from 2 to n
    for (int x = 2; x <= n; ++x) {
        int sum = 0;
        // Calculate the sum of multiples of x that are <= n
        for (int k = 1; k * x <= n; ++k) {
            sum += k * x;
        }
        // Update maxSum and optimalX if a higher sum is found
        if (sum > maxSum) {
            maxSum = sum;
            optimalX = x;
        }
    }

    return optimalX;
}

int main() {
    int t;
    cin >> t;
    vector<int> results(t);

    // Process each test case
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        results[i] = findOptimalX(n);
    }

    // Output results for all test cases
    for (const int& result : results) {
        cout << result << endl;
    }

    return 0;
}
