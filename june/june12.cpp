#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n;
    int p=0;
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		if (!(x&1))
		{
			x/=2;
		}
		else
		{
			if (p&1)
			{
				x+=1;
				p^=1;
			}
			else
			{
				x-=1;
				p^=1;
			}
			x/=2;
		}
		printf("%d\n", x);
	}
}
int main(){
    solve();
}
