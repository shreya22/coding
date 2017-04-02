#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int n;
vector<int> v[101];
stack<int> s;
queue<int> q;

void maketree()
{
    int x1, x2;
    FOR(i, n-1)
    {
        cin>>x1>>x2;
        v[x1].pb(x2);
    }
}

void bfs(int root)
{
    q.push(root);

    int temp;
    while(q.size() != 0)
    {
        temp= q.front();
        q.pop();

        cout<<temp<<" ";

        FOR(i, v[temp].size())
            q.push(v[temp][i]);
    }
    cout<<endl;
    return;
}

void dfs(int root)
{
    int temp;

    s.push(root);
    while(s.size() != 0)
    {
        temp= s.top();
        s.pop();

        cout<<temp<<" ";

        FOR(i, v[temp].size())
            s.push(v[temp][i]);
    }
    cout<<endl;
}

int main() {

    //create a tree, then apply dfs and bfs on it
    cin>>n;

    maketree();

    cout<<"bfs:\n";
    bfs(1);

    cout<<"dfs:\n";
    dfs(1);

    return 0;
}
