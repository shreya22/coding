#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 21

int n;
int a[MAX][MAX], visited[MAX][MAX]={};
int dirc[][2]= { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int cnt=0;

void dfs(int x, int y)
{
    if(x== n && y==n){
        cnt++;
        return;
    }

    visited[x][y]= 1;
    FOR(i, 4)
    {
        int dx= x + dirc[i][0];
        int dy= y + dirc[i][1];

        if(dx<1 || dx>n || dy<1 || dy>n) continue;
        if(visited[dx][dy] || a[dx][dy]) continue;
    // cout<<dx<<" "<<dy<<endl;
        dfs(dx, dy);
        visited[dx][dy]= 0;
    }

    // visited[x][y]= 0;
}


int main() {

    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        FOR1(i, n+1)
            FOR1(j, n+1)
                cin>>a[i][j];

        if(a[n][n]){
            cout<<0<<endl;
            continue;
        }

        dfs(1, 1);
        cout<<cnt<<endl;

        cnt=0;
    }

    return 0;
}
