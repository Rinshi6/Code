#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int** arr=new int* [n];
    int* sz=new int[n];
    for(int i=0;i<n;i++){
        cin>>sz[i];
    } 
    for(int i=0;i<n;i++){
        int k=sz[i];
        arr[i]=new int[k];
        for(int j=0;j<sz[i];j++){
            cin>> arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int k=sz[i];
        for(int j=0;j<sz[i];j++){
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}