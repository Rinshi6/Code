#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        vector<int> b(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            cin >> b[i];
        }

        // Calculate minimum number of operations
        int min_ops = 0;
        int mn=b[n];
        int mi=0;
        for (int i = 0; i < n; ++i) {
            if(mn>abs(b[n]-a[i])){
                mn=abs(b[n]-a[i]);
                mi=i;
            }
            min_ops+=abs(b[i]-a[i]);
            //cout<<min_ops<<" "<<mn<< endl;
        }
        int t=0;
        if(mn==0)t=1;
        else if(b[mi]>= b[n] && b[n]>=a[mi])t=1;
        else if(b[mi]<= b[n] && b[n]<=a[mi])t=1;
        else{
            t=abs(b[n]-b[mi]);
        }
        cout << min_ops+t<< endl;
    }

    return 0;
}
