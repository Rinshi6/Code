#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[12];
    
    for(int i=0;i<12;i++){
        cin>>arr[i];
    }
    bool d[12]={false};
    for(int i=0;i<12;i++){
        if(d[i]==false){
            int ele=arr[i];
            for(int j=i+1;j<12;j++){
                if(ele==arr[j])d[j]=true;
            }
        }
    }
    int c=0;
    for(int i=11;i>=0;i--){
        if(d[i]==true){
            for(int j=i+1;j<12;j++){
                arr[j-1]=arr[j];
            }
            c++;
        }
    }
    for(int i=0;i<12-c;i++){
        cout<<arr[i]<<endl;
    }
}