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
vector<int> visited;

int cnt=0;      //count of number of flips
vector<int> flip(n);    //stores elements flipped

void maketree()
{
    int x1, x2;
    FOR(i, n-1)
    {
        cin>>x1>>x2;
        v[x2-1].pb(x1-1);
    }
}

vector<int> fill_array()
{
    vector<int> x;
    int temp;
    FOR(i, n)
    {
        cin>>temp;
        x.pb(temp);
    }
    return x;
}

void dfs(int start)
{

}

int main() {

    cin>>n;
    maketree();     //fill up vector v

    current= fill_array();
    goal= fill_array();

    dfs(0);
    cout<<cnt;

    cout<<v.size();

    return 0;
}
