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

    int m, n; // m>n
    cin>>m>>n;
    int super[m], sub[n], diff[m];

    FOR(i, m) cin>>super[i];
    FOR(i, n) cin>>sub[i];

    int p=0, q=0, cnt=0;
    while(p<m && q<n)
    {
        if(super[p] == sub[q])
        {
            p++; q++;
        }
        else if(super[p] < sub[q]) {
            diff[cnt++] = super[p++];
        }
        else;
    }

    while(p<m) diff[cnt++]= super[p++];

    FOR(i, cnt) cout<<diff[i]<<" ";


    return 0;
}
