#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<vector<int>> even(n/2,vector<int>(2)), odd(n/2,vector<int>(2));

    for (int i = 0; i <n; i++) {
        cin>>a[i];
        if(i&1){
            odd[i/2][0]=a[i];
            odd[i/2][1]=i;
        }
        else {
            even[i/2][0]=a[i];
            even[i/2][1]=i;
        }
    }

    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    if(even[0][0]==1)swap(odd, even);
    vector<int> ans(n);
    for(int i=0;i<n/2;i++){
        ans[odd[i][1]]=n/2-i;
        ans[even[i][1]]=n-i;
    }
    for(auto& x:ans){
        cout<<x<<" ";

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
