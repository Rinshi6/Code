#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

using namespace std;

void print(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
            cout<< nums[i]<<", ";
        }
    cout<< endl;
}
    bool check(vector<int>& nums) {
        vector<int> arr=nums;
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<nums.size();i++){
            if(arr[i]==nums[0]) break;
        }
        print(nums);
        print(arr);
        cout<<i<<" ,";
        for(int j=0;j<nums.size();j++){
            if(arr[(j+i)<(nums.size()) ? (j+i): ((j+i)-nums.size())]!=nums[j])
            {cout<< j<< ", "<< i;
            return false;}
        }
        return true;
        
    }
int main(){
    vector<int> nums{6,10,6};
    cout<< check(nums);


}
