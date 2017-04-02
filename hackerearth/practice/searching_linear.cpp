#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    long n, m;
    cin>>n>>m;
    long a[n];

    int pos=-1;
    FOR(i, n){
        cin>>a[i];
        if(a[i] == m) pos=i+1;
    }

    cout<<pos;
    return 0;
}
