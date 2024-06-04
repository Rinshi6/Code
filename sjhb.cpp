#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,delay,forget;
    cin>>n>>delay>>forget;
    int k=forget-delay;
        queue<int> q;
        q.push(1);
        int p;
        int s;
        for(int i=2;i<n;i++){
            s=q.size();
            cout<<s<<endl;
            for(int j=0;j<s;j++){
                p=q.front();
                p++;
                if(p<forget)q.push(p);
                if(p>delay)q.push(1);
                
                q.pop();
                cout<<"p "<<p<<" ";
            }
        }
        s=q.size();
        
        int ans=0;
        while(!q.empty()){
            p=q.front();
            p++;
            if(p>delay)ans++;
            q.pop();
        }
        cout<< ans+s;
        
}