#include<bits/stdc++.h>
using namespace std;
#define fr(i, a, b) for(i=a; i<b; i++)
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second
ll min(ll a, ll b){
    return (a<b)?a:b;
}
const ll inf= 9999999999LL;
char a[50][50];
int p[50][50], n;
void bfs(int pos){
    queue<int> q;
    q.push(pos);
    int i, u, v;
    int g[]={0, 0, 1, -1};
    int h[]={1, -1, 0, 0};
    while(!q.empty()){
        pos=q.front();
        q.pop();
        u=pos/n;
        v=pos%n;

        fr(i, 0, 4){
            if(u+g[i]>=0&&u+g[i]<n&&v+h[i]>=0&&v+h[i]<n&&a[u+g[i]][v+h[i]]!='T'&&p[u+g[i]][v+h[i]]==-1){
                p[u+g[i]][v+h[i]]=p[u][v]+1;
                q.push((u+g[i])*n+v+h[i]);
            }
        }
    }
}
int main(){
    int i, j, pos, e;
    cin>>n;
    fr(i, 0, n){
        fr(j, 0, n){
            cin>>a[i][j];
            if(a[i][j]=='S')pos=i*n+j;
            if(a[i][j]=='E')e=i*n+j;
        }
    }
    memset(p, -1, sizeof p);
    p[pos/n][pos%n]=0;
    bfs(pos);
    cout<<p[e/n][e%n];
}
