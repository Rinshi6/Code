#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int fact(int s){
    if(s==1) return 1;
    cout<< s<< ", ";
    fact(s-1);
}

int main(){
    int p=6;
    fact(p);
}

