#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>> n;
        int a=1,b=0,f=0;
        
        while(n){
            
            b=b+(n%10)*a;
            a*=10;
            
            if(n%10){n=n/10;
        
            if(n && b>n){
                f=1;
                break;
            }
            }
            else n=n/10;
        }
        if(f)
        cout<<n<<" "<<b<<endl;
        else cout<<-1<<endl;
    }
}