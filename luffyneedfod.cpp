#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
	while(t--){
		int n,k;
        long long f;
		cin>>n>>k>>f;
		vector<pair<int,int>> p;
		for(int i=0;i<n;i++){
            int dis,foo;
			cin>>dis>>foo;
            p.push_back({k-dis,foo});
		}
		sort(p.begin(),p.end());
		int stop=0;
		multiset<int> food;
		int cur=0;
		bool can_reach=true;
		for(int i=1;i<k;i++){
			f--;
			if(p[cur].first==i){
				food.insert(p[cur].second);
				cur++;
			}
			if(f==0){
				if(food.size()==0){
					can_reach=false;
					break;
				}
				else{
					auto it=food.end();
					f+=*(--it);
					food.erase(it);
					stop++;
				}
			}
		}
		if(can_reach){
			cout<<stop;
		}
		else
			cout<<-1;
	}
}