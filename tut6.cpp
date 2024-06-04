            #include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int a,b;
        cin>>a;
        priority_queue<pair<int,int>> p;
        priority_queue<pair<int,int> > q;
        priority_queue<pair<int,int>> r;
        int k=3;
        for(int i=0;i<a;i++){
            cin>>b;
            if(k){
                p.push({b,i});
                k--;
            }
            else if(b>p.top().first){
                p.pop();
                p.push({b,i});
            }
        }
        k=3;
        for(int i=0;i<a;i++){
            cin>>b;
            if(k){
                q.push({b,i});
                k--;
            }
            else if(b>p.top().first){
                q.pop();
                q.push({b,i});
            }
        }
        k=3;
        for(int i=0;i<a;i++){
            cin>>b;
            if(k){
                r.push({b,i});
                k--;
            }
            else if(b>p.top().first){
                r.pop();
                r.push({b,i});
            }
        }
        int s=0;
        pair<int,int> m,n,l;
        k=3;
        
            m=p.top();
            n=q.top();
            l=r.top();
            if(m.first> n.first && m.first> l.first){
                s+=m.first;
                while(n.second==m.second){
                    q.pop();
                    n=q.top();
                }
                while(l.second==m.second){
                    r.pop();
                    l=r.top();
                }
                if(n.first> l.first){ s+=n.first;
                while(n.second==l.second){
                    r.pop();
                    l=r.top();
                }
                s+=l.first;
                }
                else{
                    s+=l.first;
                while(n.second==l.second){
                    q.pop();
                    n=q.top();
                }
                s+=n.first;
                }
            }
            if(n.first> m.first && n.first> l.first){
                s+=n.first;
                while(m.second==n.second){
                    p.pop();
                    m=p.top();
                }
                while(l.second==n.second){
                    r.pop();
                    l=r.top();
                }
                if(m.first> l.first){ s+=m.first;
                while(m.second==l.second){
                    r.pop();
                    l=r.top();
                }
                s+=l.first;
                }
                else{
                    s+=l.first;
                while(m.second==l.second){
                    p.pop();
                    m=p.top();
                }
                s+=m.first;
                }
            }
            if(l.first> m.first && l.first> n.first){
                s+=l.first;
                while(m.second==l.second){
                    p.pop();
                    m=p.top();
                }
                while(n.second==l.second){
                    q.pop();
                    n=q.top();
                }
                if(m.first> n.first){ s+=m.first;
                while(m.second==n.second){
                    q.pop();
                    n=q.top();
                }
                s+=n.first;
                }
                else{
                    s+=n.first;
                while(m.second==n.second){
                    p.pop();
                    m=p.top();
                }
                s+=m.first;
                }
            
        }
        cout<<s<<endl;
    }
}