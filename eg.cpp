#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> p;
    p.insert(34);
    p.insert(26);
    p.insert(86);
    p.insert(12);
    p.insert(85);
    p.insert(92);
    p.insert(35);
    cout<<*p.begin()<<*(--p.end());
}