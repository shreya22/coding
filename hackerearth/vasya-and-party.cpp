#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 100001
#define modulo 1000000007

int n, m;
vector<int> v[MAX], visited, temp;
vector<ll> a;

void clear_visited()
{
    visited.pb(-1);
    FOR(i, n) visited.pb(0);
}


int max_num=0, cnt=0;
void dfs(int root)
{
    visited[root]= 1;

    if(a[root] > max_num){
        max_num= a[root];

        cnt=1;
    }else if(a[root] == max_num) cnt++;
    else;

    FOR(i, v[root].size())
    {
        if(!visited[v[root][i]])
            dfs(v[root][i]);
    }
}

int main() {

    cin>>n>>m;

    int temp;
    a.pb(-1);
    FOR(i, n){
        cin>>temp;
        a.pb(temp);
    }

    ll a, b;
    FOR(i, m)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    clear_visited();

    ll ans=1;
    FOR1(i, n+1)
    {
        if(!visited[i])
        {
            dfs(i);
            ans= (ans*cnt)%modulo;
// cout<<cnt<<endl;
            cnt=0; max_num=0;
        }
    }

    cout<<ans<<endl;

    return 0;
}
