#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    string s;
    cin >> s;

    string good;
    cin >> good;

    int k;
    cin >> k;

    vector<ll> bad_pref(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); i++) {
        bad_pref[i] = bad_pref[i - 1] + (good[s[i - 1] - 'a'] == '0');
    }

    vector<ll> h(s.size() + 1, 0);
    vector<ll> power(s.size() + 1, 1);
    ll p = 31;
    ll m = 1e9 + 9;
    for (int i = 1; i <= s.size(); i++) {
        power[i] = (p * power[i - 1]) % m;
        h[i] = (h[i - 1] + (s[i - 1] - 'a' + 1) * power[i]) % m;
    }

    ll ans = 0;
    for (int l = 1; l <= s.size(); l++) {
        unordered_set<ll> hs;
        for (int i = 1; i <= s.size() - l + 1; i++) {
            if (bad_pref[i + l - 1] - bad_pref[i - 1] > k) continue;
            ll hash_val = (h[i + l - 1] + m - h[i - 1]) % m;
            hash_val = (hash_val * power[s.size() - i + 1]) % m;
            hs.insert(hash_val);
        }
        ans += hs.size();
    }

    cout << ans;
}
