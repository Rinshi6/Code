
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N=1e6;
vector<int> hf(N,0);
vector<int> distinctpf(int x){
	vector<int> ans;
	while(x>1){
		int p=hf[x];
		while(x%p==0) x=x/p;
		ans.push_back(p);
	}
	return ans;
}

int main() {
	for(int i=2;i<N;++i){
		if(hf[i]==0){
			for(int j=i;j<N;j+=i){
				hf[j]=i;
			}
		}
	}
	int p,q;
	cin>>p>>q;
	int x;
	vector<int> hsh(N,0);
	vector<int> canremove(N,0);
	for(int i=0;i<p;i++){
		cin>>x;
		hsh[x]=1;
	}
	for(int i=0;i<N;i++){
		if(hsh[i]){
			for(long long j=i;j<N;j*=i){
				canremove[j]=1;
		}
		}
	}
	while(q--){
		cin>>x;
		vector<int> pf=distinctpf(x);
		bool ispossible=false;
		for(int i=0;i<pf.size();i++){
			for(int j=i;j<pf.size();j++){
				int m=(pf[i]*pf[j]);
				if(x%m!=0 ) continue;
				int toremove=x/m;
				if(canremove[toremove]==1 || toremove==1){
					ispossible=true;
					break;
				}
			}
			if(ispossible) break;
		}
		cout<< (ispossible ? "YES\n" : "NO\n");
	}
}