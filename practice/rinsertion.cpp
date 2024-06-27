#include <bits/stdc++.h>
using namespace std;
void print(int *arr,int n){
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertion(int *arr, int n,int i){
    if(n==0) return;
    int ele=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>ele ){
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[j+1]=ele;
    return insertion(arr, n-1,i+1);
}
int main(){
    int a[9]={11,44,22,77,88,55,33,66,99};
    print(a,9);
    insertion(a,9,1);
    print(a,9);
}