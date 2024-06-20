def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        k = int(input())
        a=[]
        for i in range(n):
            x=int(input())
            a.append(x)
        
        # Sort the card counts
        a.sort()
        
        # Start from the smallest value and try to equalize
        j=0
        mx=a[0]
        for i in range(n-1):
            d=a[i+1]-a[i]
            e=d*(i+1)
            if(e<=k):
                k-=e
                j=i+1
                mx=a[j]
            else:
                mx+=(k/(i+1))
                k%=(i+1)
                break;
        if(k>0):
            mx+(k/n)
            k%=n
        print(int(mx*n+k-j),'\n')
            
solve()
# Example usage:
# You can run the `solve()` function and provide input through standard input (stdin) to test the function.
