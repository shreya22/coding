#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int n;
vector<int> v[101], a;
stack<int> s;
queue<int> q;

int cnt=0;

void maketree()
{
    int x1, x2;
    FOR(i, n-1)
    {
        cin>>x1>>x2;
        v[x1].pb(x2);
    }
}

void flip(int root)
{
    queue<int> rand;
    rand.push(root);

    int temp;
    for(int i=1; rand.size()!=0; ++i)
    {
        FOR(j, rand.size())
        {
            temp= rand.front();
            rand.pop();

            if(i%2 == 1)
                a[temp]= !a[temp];

            FOR(p, v[temp].size()) rand.push(v[temp][p]);
        }
    }
}

void dfs(int root)
{
    int temp;
    s.push(root);

    while(s.size() != 0)
    {
        temp= s.top();
        s.pop();

        if(!a[temp])     // a[temp]==0
        {
            flip(temp);
            cnt++;
        }

        FOR(i, v[temp].size())
            s.push(v[temp][i]);
    }
}

int main() {

    //create a tree, then apply dfs and bfs on it
    cin>>n;

    maketree();

    int temp; a.pb(-1);
    FOR(i, n){
        cin>>temp;
        a.pb(temp);
    }

    dfs(1);

    FOR(i, a.size()) cout<<a[i]<<" ";

    return 0;
}
