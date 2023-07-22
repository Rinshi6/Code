#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int s;
        int cnt=0;
        cin>>s;
        int arr[s];
        int i=0,sum=0,pr=1;
        while(s--){
            cin>>arr[i];
            sum+=arr[i];
            pr*=arr[i];
        }
        if(sum<0){
            cnt-=sum/2; 
            if(((-1)*sum)%2!=0) 
                cnt+=1; 
            if(pr*pow(-1,cnt)==-1) 
                cnt+=1;}
        else if(pr<0) 
            cnt+=1;
        cout<< cnt;
    }
}