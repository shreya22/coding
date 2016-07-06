     #include <iostream>
    #include<algorithm>
    #include<cstdio>
    #include<cstring>
    #include<cmath>
    using namespace std;
    int gcdiv(int a, int b, int i)
    {
    if(i==0)
    {
    if(a<b) swap(a, b);
    i=1;
    }
    if(b==0) return a;
    else
    return gcdiv(b, a%b, i);
    }
    int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
    long int n, q, gcd=0, flag=0;
    cin>>n>>q;
    int a[n], l[q], r[q], frw[n], rev[n];
    for(int i=0; i<n; ++i)
    {
    scanf("%d", &a[i]);
    if(i==0) frw[i]= a[i];
    else
    {
    frw[i]= gcdiv(a[i], frw[i-1], 0);
    }
    }
    for(int i=n-1; i>=0; --i)
    {
    if(i==n-1) rev[i]= a[i];
    else
    rev[i]= gcdiv(rev[i+1], a[i], 0);
    }
    int ans=0;
    for(int i=0; i<q; ++i)
    {
    scanf("%d%d", &l[i], &r[i]);
    l[i]= l[i]-1;
    r[i]= r[i]-1;
    if(l[i] == 0)
    ans= rev[r[i] + 1];
    else if(r[i] == n-1)
    ans= frw[l[i] - 1];
    else
    {
    ans= gcdiv(frw[l[i] - 1], rev[r[i] + 1], 0);
    }
    cout<<ans<<endl;
    }
    }
    return 0;
    } 
