#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int bitc = (int)log2(x) + 1;
    int a = 0, b = 0;
    vector<int> setbit;
    for (int i = 0; i < bitc; i++)
    {
        if (x & (1 << i))
        {
            setbit.push_back(i);
        }
        else
        {
            b |= 1 << i;
            a |= 1 << i;
        }
    }
    int sz=1<<setbit.size();
    long long ans=-1;
    for(int i=0;i<sz;i++){
        int ac=a, bc=b;
        for(int j=0;j<setbit.size();j++){
            if(i &(1<<j)) ac |= (1<<setbit[j]);
            else bc |=(1<<setbit[j]);
        }
        ans=max(ans,ac*1LL*bc);
    }
    cout<< ans;
}