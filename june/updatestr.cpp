#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
  int n,m,x;
  string s,u;
  cin>>n>>m>>s;
  set<int> st;
  for(int i=0;i<m;i++){
    cin>>x;
    st.insert(x);
  }
  cin>>u;
  sort(u.begin(),u.end());
  int i=0;
  
  for(int y: st){
    s[--y]=u[i++];
  }
  cout<<s<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}