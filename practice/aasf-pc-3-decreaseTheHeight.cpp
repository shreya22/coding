#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

long min(long a, long b){
    return (a>b)?b:a;
}

int main() {

    int n; cin>>n;
    long a[n];

    int p; long cnt=0;
    cin>>p;
    FOR1(i, n){
        cin>>a[i];
        if(a[i]>p) cnt+= a[i]-p;
        p= min(a[i], p);
    }
    cout<<cnt;

    return 0;
}
