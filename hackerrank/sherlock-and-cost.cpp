#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int b[n], a[n], diff=0;
        FOR(i, n) cin>>b[i];

        if(n>1) a[0]= (b[1]<b[0])?b[0]:1;
        FOR1(i, n){
            a[i]= (b[i]>a[i-1])?b[i]:1;
            diff+= abs(a[i]- a[i-1]);
        }

        // FOR(i, n) cout<<a[i]<<" ";

        cout<<diff<<endl;
    }

    return 0;
}
