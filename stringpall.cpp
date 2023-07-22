
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
    bool isPalindrome(string s) {

    string m;
    for(int i=0;i<s.size();i++){
        if(s[i]>64 && s[i]<91)
        m.push_back(s[i]);
        else if(s[i]>96 && s[i]<123)
        m.push_back(s[i]);
    }
    for(int i=0;i<(m.size());i++){
            cout<<m[i]<<", ";
            }
    cout<<endl;
    
        for(int i=0;i<(m.size()/2);i++){
            if(m[i]!=m[m.size()-1-i]) {cout<< i<< ", ";return false;
            }}
        return true;
    }
int main(){
    string q={"A man, a plan, a canal: Panama"};
    cout<< isPalindrome(q);
}