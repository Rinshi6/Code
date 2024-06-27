#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to perform Sieve of Eratosthenes and return primes up to sqrt(n)
vector<ll> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// Function to find primes in range [a, b] using segmented sieve method
void solve() {
    ll a, b;
    cin >> a >> b;
    
    if (a < 2) a = 2; // Ensure that the range starts from at least 2
    ll limit = sqrt(b) + 1;
    vector<ll> primes = sieve(limit);
    vector<bool> is_prime(b - a + 1, true);
    
    for (const ll &p : primes) {
        ll start = max(p * p, (a + p - 1) / p * p); // Find the starting point
        for (ll j = start; j <= b; j += p) {
            is_prime[j - a] = false;
        }
    }
    
    for (ll i = 0; i <= b - a; ++i) {
        if (is_prime[i]) {
            cout << i + a << endl;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
