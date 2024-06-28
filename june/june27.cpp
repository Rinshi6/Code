#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    int x=0,y=0,nx=0,ny=0;
    vector<int> a(n), b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)
        x++;
        else if(b[i]==-1)nx++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]==1)
        y++;
        if(b[i]==-1)
        ny++;
    }
    int sa=0,sb=0;
    for(int i=0;i<n;i++){
        if(a[i]==0 && b[i]==0)continue;
        else if(a[i]==1 && b[i]==1){
            continue;
        }
        else if(a[i]==-1 && b[i]==-1)continue;
        if(a[i]==1)sa++;
        if(b[i]==1)sb++;
    }
    for(int i=0;i<n;i++){
        if(a[i]==0 && b[i]==0)continue;
        else if(a[i]==1 && b[i]==1){
            if(sa>sb)sb++;
            else if(sb>sa)sa++;
            else if(x>y)sb++;
            else if(y>x)sa++;
            else if(nx>ny)sa++;
            else sb++;
        }
        else if(a[i]==-1 && b[i]==-1){
            if(sa>sb)sa--;
            else if(sb>sa)sb--;
            else if(x>y)sa--;
            else if(y>x) sb--;
            else if(nx>ny)sb--;
            else sa--;
        }  
        if(a[i]==1)
        x--;
        else if(b[i]==-1)nx--;
        if(b[i]==1)
        y--;
        if(b[i]==-1)
        ny--;

    }
    cout<<min(sa,sb)<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}