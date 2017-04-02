#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int n;
vector<int> v[51], vis;
int u, v, k;
int cnt=0


void dfs(int init, int len){
    if(vis[int]) return;

    if(len == k && init == v){
        cnt++; return;
    }

    FOR(i, v[init].size()){
        if(!vis[v[init][i]]){

            vis[v[init][i]]= 1;
            dfs(v[init][i], len+1);
            vis[v[init][i]] =0;
        }
    }

}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;

        int temp;
        FOR(i, n)
        {
            FOR(j, n)
            {
                cin>>temp;
                if(temp) v[i].pb(j);
            }
            vis.pb(0);
        }

        cin>>u>>v>>k;
        bfs(u, 0);
    }

    return 0;
}
