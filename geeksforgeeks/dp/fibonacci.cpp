#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 1000

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int lookup[MAX];

int fib_top_down(int n)
{
    if(lookup[n] == -1){
        if(n<=1) lookup[n]= n;
        else lookup[n]= fib_top_down(n-1) + fib_top_down(n-2);
    }
    return lookup[n];
}

int fib_bottom_up(int n)
{
    int f[n+1];
    f[0]= 0; f[1]= 1;
    for(int i=2; i<=n; ++i)
        f[i]= f[i-1]+ f[i-2];

    return f[n];
}

int main() {
    memset(lookup, -1, MAX);
    int n;
    cin>>n;

    cout<<fib_top_down(n)<<endl;
    cout<<fib_bottom_up(n)<<endl;

    return 0;
}
