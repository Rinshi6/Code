#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void update( int*c,int*d){
    *c=*c+*d;
    if(*c<*d){
        *d=*c-2*(*d);
    }
    else /*if(*c>*d)*/{
        *d=2*(*d)-*c;
    }
}


int main() {
    int a,b;
    cin>>a>>b;
    update(&a,&b);
    cout<<a<<"\n"<<b;   
    return 0;
}
