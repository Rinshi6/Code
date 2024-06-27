
#include <bits/stdc++.h>
using namespace std;
/*
char upper(char s)
{
    return 'A'+s-'a';
}
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        string s;
        cin>> s;
        for(int i=0; i<s.size(); i++)
        {
            cout<< upper(s[i]);
        }
    }
}

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        int p=1;
        while(n)
        {
            p=p*(n%10);
            n/=10;
        }
        if (((p%10)==2) || ((p%10)==3) || ((p%10)==5) )
        {
            cout<< "true";

        }
    }
}



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        string s;
        cin>> s;
        int p=0,q=1;
        for(int i=s.size()-1; i>=0; i--)
        {
            p+=q*(int)(s[i]-'0');
            q*=2;
            cout<<p<<"  "<<q<<endl;
        }
        cout<< p;
    }
}



int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int i;
    for(i=0;c>=0;i++)
    {
        if ((i%a==0) || (i%b==0))
        {
            c--;
        }
    }
    int cth=i-1;
    i=1;
    if ((cth%a==0) && (cth%b==0))
    {
        while(true)
        {
            if((i%a==0) && (i%b==0))
            break;
            i++;
        }
        for(int j=cth;j>=0;j-=i)
        {
            cout<< j<<" ";
        }
    }
    else if (cth%a==0)
    {
        for(int j=cth;j>=0;j-=a)
        {
            cout<< j<<" ";
        }
    }
    else if (cth%b==0)
    {
        for(int j=cth;j>=0;j-=b)
        {
            cout<< j<<" ";
        }
    }
}

*/

const int N=1e3+10;
int pf[N];

int main()
{
    int b,c;
    cin>> b;
    int a[b];
    for (int i=1; i<=b; i++)
    {
        cin>> a[i];
        pf[a[i]]=pf[a[i]]+1;
    }
    
    int q;
    cin>> q;

    while(q--)
    {
        int c;
        cin>> c;
        cout<<"out"<< pf[c];
    }

}



