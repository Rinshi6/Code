#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
  ll x,y,k,p;
  cin>>x>>y>>k;
  if(y==1){
    cout<<x+k<<endl;
    return;
  }
  x++;
  k--;
  while (x % y == 0) {
      x /= y;
  }
  while(k>0){
    
    p=k;
    k-=(y-(x%y ? x%y : 0));
    if(k>=0){
      x/=y;
      x++;
    }
    while (x % y == 0) {
      x /= y;
    }
    if(x==1){
      ll cn=y-1;
      k%=cn;
      cout<<1+k<<endl;
      return;
    }
    
  }
  if(k<0)
  cout<<x+p<<endl;
  else cout<<x<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
      solve();
    }
}