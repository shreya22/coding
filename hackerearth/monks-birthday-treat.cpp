#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int cnt=0, min_num=10001;
vector<int> v[1001], store, visited;


void dfs(int root)
{
    cnt++; // cout<<root<<" ";
    visited[root-1]= 1;

    FOR(i, v[root].size())
        if(!visited[v[root][i] -1])
            dfs(v[root][i]);

    return;
}

void clear_visited()
{
    FOR(i, visited.size())
        visited[i]= 0;
}

int main() {

    int n, d;
    cin>>n>>d;

    int a, b;
    FOR(i, d)
    {
        cin>>a>>b;
        v[a].pb(b);
    }

    FOR(i, n) visited.pb(0);
    FOR1(i, n+1)
    {
        dfs(i);
        min_num= min(cnt, min_num);
        // cout<<"boo "<<i<<" "<<cnt<<endl;
        clear_visited();
        cnt=0;
    }

    cout<<min_num;

    return 0;
}
