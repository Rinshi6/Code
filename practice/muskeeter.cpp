#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
    int sz=1<<p.size();
    for(int i=0;i<sz;i++){
        vector<string> a;
        for(int j=0;j<p.size();j++){
            if(i&(1<<j)) a.push_back(p[j]);
        }
        if(a.size()) ans.push_back(a);
    }
    return ans;
}
*/
bool isvowel(char ch){
    return (ch=='a') | (ch=='e') | (ch=='i') | (ch=='o') | (ch=='u');
}
int main() {
	int t;
	cin>> t;
	string c[5]={"a","e","i","o","u"};
	while(t--){
		int x;
		cin>> x;
        unordered_map<string, int> p;
		for(int i=0;i<x;i++){
            string s;
			cin>>s;
            set<char> m;
			for(int k=0;k<s.size();k++){
				if(isvowel(s[k]) ) m.insert(s[k]);
			}
            string w;
            for(auto ch: m){
                w.push_back(ch);
            }
            int sz=1<<w.size();
            for(int k=0;k<sz;k++){
                string u="";
                for(int j=0;j<w.size();j++){
                    if(k&(1<<j)) u+=w[j];
                }
                if(u.size())
                p[u]++;
            }    
		}
        int cnt=0;
        for(auto z: p){
            int n=z.second;
            int m=z.first.size();
            int a=(n)*(n-1)*(n-2)/6;
            if(n>2 && m%2!=0){ 
                cnt+=a;
            }
            else if(n>2){
                cnt-=a;
            }
        }
        cout<<cnt;
	}
}