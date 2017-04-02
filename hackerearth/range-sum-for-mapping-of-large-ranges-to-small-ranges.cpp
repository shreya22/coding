#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 100001
#define MODULO 1000000007


int n, k;
vector<int> a[MAX];
int visited[MAX]={};
int cnt=0;

void dfs(int root)
{
    stack<int> s;
    s.push(root);

    cnt++;
    while(s.size())
    {
        int temp= s.top();
        s.pop();

        visited[temp]= 1;

        FOR(i, a[temp].size())
        {
            if(!visited[a[temp][i]])
            {
                s.push(a[temp][i]);
                cnt++;
            }

        }
    }
}

void clear_list()
{
    FOR1(i, n+1)
    {
        a[i].clear();
        visited[i]=0;
    }
}


int main() {

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;

        int x, y;

        FOR(i, k)
        {
            cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);
        }

        ll mul=1;
        FOR1(i, n+1)
        {
            if(!visited[i]){
                dfs(i);
//cout<<i<<" "<<cnt<<endl;
                if(cnt != 1) mul= (mul*cnt*(cnt-1)/2)%MODULO;
                cnt=0;
            }
        }
        cout<<mul<<endl;

        clear_list();

    }

    return 0;
}
