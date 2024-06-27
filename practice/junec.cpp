#include<iostream>
#include <iomanip>
#include<math.h>
#include <bits/stdc++.h>
#include<set>
#include<map>
#include<queue>
#include <fstream>
using namespace std;

#define float long double
#define PYes cout<<"Yes\n"
#define PNo cout<<"No\n"
#define PYES cout<<"YES\n"
#define PNO cout<<"NO\n"
#define pq priority_queue
#define int long long
#define ll long long
#define endl '\n'
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define ff first
#define fs second
#define fr(i,a) for(int i=0;i<a;i++)
#define fb(i,a) for(int i=a;i>=0;i--)

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef vector<pair<int,int>> vp;
#define sz(a) int((a).size())
#define pb push_back

#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
const int inf = 1LL<<60;
const int N=1e9;

void solve(){
    ll n,m;
    cin >> n>> m;
    vector<vector<int>> v1(n,vector<int> (m,0));
    vector<vector<int>> v2(n,vector<int> (m,0));
    fr(i,n){
        fr(j,m){
            cin >> v1[i][j];
        }
    }
    fr(i,n){
        fr(j,m){
            cin >> v2[i][j];
        }
    }
    vector<int> arr(n*m+1,-1);
    fr(i,n){
        int curr=-1;
        fr(j,m){
            if(curr==-1){
                arr[v1[i][j]]=v1[i][j];
                curr=v1[i][j];
            }else{
                arr[v1[i][j]]=curr;
            }
        }
    }
    fr(i,n){
        int curr=-1;
        fr(j,m){
            if(curr==-1){
                curr=arr[v2[i][j]];
            }else if(arr[v2[i][j]]!=curr){
                PNO;
                return;
            }
        }
    }
    vector<int> brr(n*m+1,-1);

    fr(i,m){
        int curr=-1;
        fr(j,n){
            if(curr==-1){
                brr[v1[j][i]]=v1[j][i];
                curr=v1[j][i];
            }else{
                brr[v1[j][i]]=curr;
            }
        }
    }
    fr(i,m){
        int curr=-1;
        fr(j,n){
            if(curr==-1){
                curr=brr[v2[j][i]];
            }else if(brr[v2[j][i]]!=curr){
                PNO;
                return;
            }
        }
    }
    PYES;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}