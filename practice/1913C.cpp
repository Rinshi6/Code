#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,cnt[30]={0};cin>>n;
	while(n--){
		int a,x;cin>>a>>x;
		if(a==1)
			cnt[x]++;
		else{
			for(int i=29;i>=0;i--)
				x-=min(x>>i,cnt[i])<<i;
			if(x==0)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
}