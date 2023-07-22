#include <bits/stdc++.h>
using namespace std;
    string longestPalindrome(string s) {
        int cnt;
        vector<string> p;
        int l=0,m=0;
        if(s.size()<2) return s;
        if(s.size()==2) {
            if(s[0]==s[1]) return s;
            else return s.substr(0,1);
        }
        for(int i=0;i<s.size()-1;i++){
            int j,k;
            int p=i;
            while(true){
                if(s[i]!=s[++p]) break;
            }
            j=i-1;
            k=p;

            while(j>=0 && k<s.size()){
                if(s[j] != s[k]) {
                    break;} 
                --j;
                ++k;
            }
            ++j;--k;
        
            if((k-j) > (m-l)){
                l=j;
                m=k;
            }
        }
        return s.substr(l,m-l+1);
    }

    int main(){
        string g="cbbd";
        string q=longestPalindrome(g);
        cout<< q;
    }