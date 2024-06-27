#include<bits/stdc++.h>
using namespace std;
int main(){
        vector<int> nums={5,7,7,8,8,10};
        int target=8;
        //int s=0,e=nums.size()-1;
        //int m;
        
        vector<int> fl;
        /*
        while(s<e){
            m=s+(e-s)/2;
            if(nums[m]<target) s=m+1;
            else e=m;
        }
        cout<<s<<endl;
        fl.push_back(nums[s]);
        */
        int s=0,e=nums.size()-1;
        int m;
        while(s<=e){
            m=s+(e-s)/2;
            if(nums[m]<=target) s=m+1;
            else e=m;
        }
        fl.push_back(nums[e]);
        cout<<"jyf"<<e;
    
}