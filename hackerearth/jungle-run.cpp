#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define pq push
#define ll long long
#define MAX 31

int n;
string a[MAX][MAX];
int dirn[4][2]= { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int a1, b1, a2, b2; //(a1, b1)=>start, (a2, b2)=>end
int cnt[MAX][MAX];
int s, e;

int dx, dy;
void bfs(int pos)
{
    queue<int> q;
    q.pq(pos);

    // if(pos/n== e/n && pos%n==e%n) return;

    while(q.size())
    {
        int temp= q.front();
        q.pop();

        int x= temp/n;
        int y= temp%n;

        FOR(i, 4)
        {
            dx= x+dirn[i][0]; dy= y+dirn[i][1];

            if(dx<0 || dx>=n || dy<0 || dy>=n) continue;
            if(a[dx][dy]=="T" || cnt[dx][dy] != -1) continue;

            q.pq(dx*n+dy);
            cnt[dx][dy]= cnt[x][y]+1;
        }
    }

}

int main() {

    cin>>n;

    FOR(i, n)
        FOR(j, n)
        {
            cin>>a[i][j];
            if(a[i][j] == "S"){
                s= i*n+j;
            }

            if(a[i][j] == "E"){
                e= i*n+j;
            }
        }

    memset(cnt, -1, sizeof cnt);
    bfs(s);
    cout<<cnt[e/n][e%n]+1;


    return 0;
}
