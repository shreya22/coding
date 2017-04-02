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

void swap(int *p, int *q)
{
    int temp;
    temp= *p;
    *p= *q;
    *q= temp;
}

int main() {

    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        long s[n];
        FOR(i, n) cin>>s[i];

        int v; cin>>v;
        set<long> sizeSet;
        int p, q;

        FOR(i, v){
            cin>>p>>q;
            if(p>q) swap(&p, &q);

            for(int i=p; i<=q; ++i) sizeSet.insert(i);
        }

        long count=0;
        FOR(i, n)
            if(sizeSet.find(s[i])!= sizeSet.end()) count++;

        cout<<count<<endl;

    }

    return 0;
}
