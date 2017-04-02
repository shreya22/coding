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

    int m, n;
    cin>>m>>n;
    int a1[m], a2[n], ans[min(m, n)];

    FOR(i, m) cin>>a1[i];
    FOR(i, n) cin>>a2[i];

    sort(a1, a1+m);
    sort(a2, a2+n);

    int p=0, q=0, cnt=0;
    while(p<m && q<n)
    {
        if(a1[p] == a2[q]){
            ans[cnt++]= a1[p];
            p++; q++;
        }
        else if(a1[p] < a2[q]) p++;
        else q++;
    }

    FOR(i, cnt) cout<<ans[i]<<" ";

    return 0;
}
