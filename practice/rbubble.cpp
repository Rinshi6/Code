#include <bits/stdc++.h>
using namespace std;
void print(int *arr,int n){
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubble(int *arr, int n){
    if(n==0) return;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])swap(arr[i],arr[i+1]);
    }
    return bubble(arr, n-1);
}
int main(){
    int a[9]={11,44,22,77,88,55,33,66,99};
    print(a,9);
    bubble(a,9);
    print(a,9);
}