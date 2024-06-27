#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> p;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			p.push_back(x);
		}
        sort(p.begin(),p.end());
		int m;
		cin>>m;
		vector<int> v;
        set<int> s;
		for(int i=0;i<m;i++){
			int x;
			cin>>x;
            int it=upper_bound(p.begin(),p.end(),x)-lower_bound(p.begin(),p.end(),x);
            while(it--){
            cout<<x<<" ";
            }
            s.insert(x);
		}
		for(int ele: p){
            auto ite=s.find(ele);
			if(ite==s.end())
            cout<<ele<<" ";
		}
		cout<<"\n";
	}
}