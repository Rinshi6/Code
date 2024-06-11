#include <iostream>
#include <vector>
#include <algorithm>

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> k(n);
        for (int i = 0; i < n; ++i) {
            cin >> k[i];
        }

        long long total_bet = 232792560;
        vector<long long> bets(n);
        for (int i = 0; i < n; ++i) {
            bets[i] = total_bet / k[i];
        }

        bool possible = true;
        if (accumulate(bets.begin(), bets.end(), 0LL) >= total_bet) {
            possible = false;
        }
        

        if (possible) {
            for (long long bet : bets) {
                cout << bet << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
