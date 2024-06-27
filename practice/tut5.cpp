#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>> a>>b;
    int c=a+b;
    int arr[c];
    for(int i=0;i<c;i++){
        cin>> arr[i];
    }
    int p=0,q=0,k=1,l=1;
    for(int i=0; i<a;i++){
        
        p+=arr[a-i-1]*k;
        k*=10;
    }
    for(int i=0;i<b;i++){
        q+=arr[a+b-i-1]*l;
        l*=10;
    }
    cout<<p << " "<<q<<"   " <<p*q;
}