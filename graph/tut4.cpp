#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int> &nums,int target,int ans,int index)
    {
        if(ans==target)
          return 1;
        if(index>=nums.size())
          return 0;

        return solve(nums,target,ans+nums[index],index+1) || solve(nums,target,ans,index+1);
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
            int ans=0,i=0;
            bool k= solve(nums,b,ans,i);
        
            if(k) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}