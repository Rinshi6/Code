#include <bits/stdc++.h>
using namespace std;

int main()
{    
    int u;
    cin>> u;
    while (u--)
    {
        int k,n;
        cin>>k>>n;
        int i=n,l=n;
        int a[k+n];
        int j=k-1,p=k;
        while (k--)
        {
            int c;
            cin>> c;
            a[i]=a[i-1]+c;
            i++;
            
        }
        int ar[k],r=0,t;
        while (p--)
        {
            ar[r]=0;
            t=0;
            while(n--)
            {
                ar[r]+=ar[r+t];
                t++;
            }
            r++;
        }

        
        int max;
        i=0;
        max=ar[0];
        while (j--)
        {
            if (max<ar[i])
            {
                max=ar[i];
            
            }
            i++;
        }
        cout<<"output"<< max;
    }
}



int main(){
    int i,j;
    for(i=1;i<10;i++){
        for(j=0;j<i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

