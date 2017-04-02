#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 31

int n;
int steps[MAX][MAX];
string a[MAX][MAX];
int s, e;
int dirn[4][2]= { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void bfs(int pos)
{
    queue<int> q;
    q.push(pos);

    while(q.size())
    {
        int temp= q.front();
        q.pop();

        if(temp == e) return;

        int x= temp/n;
        int y= temp%n;

        FOR(i, 4)
        {
            int dx= x+dirn[i][0];
            int dy= y+dirn[i][1];

            if(dx<0 || dx>=n || dy<0 || dy>=n) continue;
            if(steps[dx][dy]!=0 || a[dx][dy]=="T") continue;
// cout<<"wohoo";
            steps[dx][dy]= steps[x][y]+1;
            q.push(dx*n+dy);
        }
    }

}

int main() {

    cin>>n;
    FOR(i, n)
    {
        FOR(j, n)
        {
            cin>>a[i][j];
            steps[i][j]=0;

            if(a[i][j] == "S") s= i*n+j;
            if(a[i][j] == "E") e= i*n+j;
        }
    }

    bfs(s);
    cout<<steps[e/n][e%n];

    return 0;
}
