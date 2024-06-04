#include <bits/stdc++.h>
using namespace std;

int maxi(int s,int b,vector<int> &p,vector<int> &q,int ind){
    if(b==0){return s;}
    
    s+=p[ind];b--;
    int Max=s;
    if(ind<p.size()-1){ind++;
    //if(b==0)return s;
    Max=maxi(s,b,p,q,ind);
    int z=b;
    for(int i=0;i<z;i++){
        s+=q[ind];
        b--;
        //if(b==0)return s;
        Max=max(maxi(s,b,p,q,ind),Max);
    }
    
    }
    else if(ind==p.size()-1){
        for(int i=0;i<b;i++){
            s+=q[ind];
            
        //if(b==0)return s;
        }
        Max=max(Max,s);
    }
    return Max;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;
        vector<int> p(a),q(a);
        for(int i=0;i<a;i++){
            cin>>p[i];
        }
        for(int i=0;i<a;i++){
            cin>>q[i];
        }
        int s=0;
        
        int m=maxi(s,b,p,q,0);
        cout<<m<<endl;
    }
}
