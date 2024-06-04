            #include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int a;
        cin>>a;
        vector<int,int> p(a),q(a),r(a);
        vector<int> ma(3,INT_MIN),mb(3,INT_MIN),mc(3,INT_MIN),mia(3),mib(#),mic(3);

        for(int i=0;i<a;i++){
            cin>>p[i];
            for(int j=0;j<3;j++){
                if(ma[j]<p[i]){
                    ma=p[i];
                    mia=i;
                    break;
                }
            }
        }
        for(int i=0;i<a;i++){
            cin>>q[i];
            for(int j=0;j<3;j++){
                if(mb[j]<q[i]){
                    mb=q[i];
                    mib=i;
                    break;
                }
            }
        }
        for(int i=0;i<a;i++){
            cin>>r[i];
            for(int j=0;j<3;j++){
                if(mc[j]<r[i]){
                    mc=r[i];
                    mic=i;
                    break;
                }
            }

        }
        int s=0,i;
        int mx=max(ma[0],max(mb[0],mc[0]));
        s+=mx;
        char c;
        if(mx==ma[0]){i=mia[0];c='a';}
        if(mx==mb[0]){i=mib[0];c='b';}
        if(mx==mc[0]){i=mic[0];c='c';}

        if(c='a'){
            
        }
    }
}