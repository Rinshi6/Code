#include <bits/stdc++.h>
using namespace std;
void print(int *arr,int n){
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int* arr, int s, int mid, int e){
    int m=mid-s+1;
    int n=e-mid;
    int l=e-s+1;
    int arr1[m+1],arr2[n+1];
    for(int k=s;k<=mid;k++){
        arr1[k-s]=arr[k];
    }
    for(int k=mid+1;k<=e;k++){
        arr2[k-mid-1]=arr[k];
    }
    arr1[m]=arr2[n]=INT_MAX;
    int i=0,j=0;
    for(int k=s;k<=e;k++){
        if(arr1[i]>arr2[j]){arr[k]=arr2[j]; j++;}
        else{
            arr[k]=arr1[i];i++;
        }
    }
    return;
}
void mergesort(int* arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);
    merge(arr, s, mid, e);
}
int main(){
    int a[9]={11,44,22,77,88,55,33,66,99};
    print(a,9);
    mergesort(a,0,8);
    print(a,9);
}