#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> b(n,0);
        int c=1;
        vector<int> sol;
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sol.push_back(b[0]);
        for(int i=1;i<n;i++){
            if(b[i-1]<=b[i]){
                sol.push_back(b[i]);
                c++;
            }
            else{
                if(b[i]==1){
                   sol.push_back(1);
                    sol.push_back(1);
                    c+=2; 
                }
                else{
                    sol.push_back(b[i]-1);
                    sol.push_back(b[i]);
                    c+=2;
                }
            }
        }
        cout<<c<<endl;
        for(int i=0;i<c;i++){
            cout<<sol[i]<<" ";
        }
        cout<<endl;
    }
}