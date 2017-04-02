#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for( i=0; i<n; ++i)
#define FOR1(i, n) for( i=1; i<n; ++i)
#define FORrev(i, n) for( i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
int v[101][101];
int visited[101][101]={};

int n, m;
int X1, Y1;
int X2, Y2;

int dfs(int x, int y)
{
    if(visited[x][y]) return 0;

    if(x== X2 && y==Y2) return 1;
    visited[x][y]= 1;

    if(x-1 >0)
        if(v[x-1][y] > v[x][y])
            if(dfs(x-1, y))
                return 1;

    if(x+1 <=n)
        if(v[x+1][y] > v[x][y])
            if(dfs(x+1, y))
                return 1;

    if(y-1 >0)
        if(v[x][y-1] > v[x][y])
            if(dfs(x, y-1))
                return 1;

    if(y+1 <=m)
        if(v[x][y+1] > v[x][y])
            if(dfs(x, y+1))
                return 1;

    return 0;
}

int main() {

    int t;
    cin>>t;

    while(t--)
    {int i, j;
        cin>>n>>m>>X1>>Y1>>X2>>Y2;

        FOR1(i, n+1)
            FOR1(j, m+1)
            {
                cin>>v[i][j];
                visited[i][j]= 0;
            }

        int res= dfs(X1, Y1);

        if(res) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
