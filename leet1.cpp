#include <bits/stdc++.h>
using namespace std;
   int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        if(n!=s2.size()){
            return -1;
        }
        int k=0,m=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='1')k++;
            if(s2[i]=='1')m++;
        }
        if(k!=m) return -1;
        vector<int> a,b;
        int cost=0;
        for(int i=n-1;i>=0;i--){
            if(s1[i]=='0' && s2[i]=='1'){
                a.push_back(i);
            }
            if(s1[i]=='1' && s2[i]=='0'){
                b.push_back(i);
            }   
        }
        for(int i=0;i<a.size();i++){
            int k=a[i]-b[i];
            if(k==1)cost++;
        }
        
        k=-2;
        m=-2;
        if(s1!=s2){
            for(int i=0;i<n;i++){
                if(s1[i]=='0' && s2[i]=='1'){
                    
                }
                if(s1[i]=='1' && s2[i]=='0'){
                    m=i;
                }
                if(abs(k-m)>1){
                    cost+=x;
                    s1[k]='1';
                    s1[m]='0';
                    k=-2;
                    m=-2;
                    cout<<i<<endl;
                }
                if(abs(k-m)==1){
                    cost+=1;
                    s1[k]='1';
                    s1[m]='0';
                    k=-2;
                    m=-2;
                    cout<<i<<endl;
                }   
            }
        }
        return cost;     
    }

    int main(){
        string s1 = "1100011000";
        string s2 = "0101001010";
        int x = 2;
        cout<< minOperations(s1, s2, x);

    }