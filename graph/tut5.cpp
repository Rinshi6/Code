#include <bits/stdc++.h>
using namespace std;
bool check(int start, int n, vector< int> &arr,  int r,bool ans)
{

    if (start >= n)
    {
        return r == 0 && ans;
    }
   
    if (check(start + 1, n, arr, r, ans))
    {
        return true;
    }
    
    return check(start + 1, n, arr, r - arr[start], true);
}


int main(){
    int t;
    cin>>t;
    vector<int> nums;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==1)
            nums.push_back(pow(2,b));

        else{
            
        
            bool k=check(0, nums.size(), nums, b, false);
            if(k) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}