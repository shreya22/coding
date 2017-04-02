#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long


ll n, m;
vector<ll> a, v[100001];
int visited[100001];

ll cntb=0;
ll maxb=0;

void dfs(int root)
{
    visited[root]= 1;
    cntb+= a[root];
    FOR(i, v[root].size())
        if(!visited[v[root][i]])
            dfs(v[root][i]);

    return;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        int x, y;
        FOR(i, m)
        {
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }

        a.pb(-1);
        ll temp;
        FOR(i, n){
            cin>>temp;
            a.pb(temp);

            visited[i+1]= 0;
        }

        FOR1(i, n+1)
        {
            if(!visited[i]) dfs(i);
            maxb= max(maxb, cntb);

            cntb=0;
        }

        cout<<maxb<<endl;

        cntb=0; maxb=0;
        FOR1(i, n) v[i].clear();
        a.clear();
    }


    return 0;
}
