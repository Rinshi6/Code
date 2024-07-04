#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), c(n);
    iota(a.begin(), a.end(), 1);

    int q=1;
    vector<int> ans;
    int s=1;
    for(int i=0;i<n;i++){
        if(2*abs(i+1-s)<=k)ans.push_back(q);
        else{
            s=i+1;
            q++;
            ans.push_back(q);
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<q<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
