#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int n;
vector< vector<int> > v(100001);
vector<int> goal, current;
stack<int> s;
queue<int> q;

vector<int> visited;

int cnt=0;      //count of number of flips
vector<int> flip;    //stores elements flipped

void maketree()
{
    int x1, x2;
    FOR(i, n-1)
    {
        cin>>x1>>x2;
        v[x2].pb(x1);
    }
}

vector<int> fill_array()
{
    vector<int> x;
    int temp;

    x.pb(-1);
    FOR(i, n)
    {
        cin>>temp;
        x.pb(temp);
    }
    return x;
}

void toggle(int root)
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
                current[temp]= !current[temp];

            FOR(p, v[temp].size()) rand.push(v[temp][p]);
        }
    }
}

void dfs(int root)
{
    int temp;
    if(!visited[root])
    {
        s.push(root);
        visited[root]= 1;

        while(s.size() != 0)
        {
            temp= s.top();
            s.pop();

            //cout<<temp<<endl;

            if(current[temp] != goal[temp])     // a[temp]==0
            {//cout<<"wohoo"<<endl;
                toggle(temp);
                flip.pb(temp);
            }

            FORrev(i, v[temp].size())
                s.push(v[temp][i]);
        }
    }

}

int main() {

    cin>>n;
    maketree();     //fill up vector v

    visited.pb(-1);
    FOR(i, n) visited.pb(0);

    current= fill_array();
    goal= fill_array();

    dfs(1);
    // cout<<"---------------------------------"<<endl;
    // cout<<flip.size()<<endl;

    // FOR(i, flip.size()) cout<<flip[i]<<endl;

    FOR(i, current.size()) cout<<current[i]<<" "; cout<<endl;
    FOR(i, goal.size()) cout<<goal[i]<<" ";

    return 0;
}
