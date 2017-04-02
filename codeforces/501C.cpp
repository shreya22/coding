// getting segmentation fault, unable to resolve

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(ll i=0; i<n; ++i)
#define FOR1(i, n) for(ll i=1; i<n; ++i)
#define FORrev(i, n) for(ll i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

ll n;
struct str{
    ll deg;
    ll s;
};

struct edge{
    ll x1;  //edge 1
    ll x2;  //edge 2
} tree_edge;

vector<str> v;      //tre details as input
vector<edge> tree;  //edges of tree
vector<ll> temp;    //vector to store indices of index to be deleted in each iteration
int cnt=0;

void maketree()
{
    while(!v.empty())   //iterate till input present
    {
        cnt=0;
        FOR(i, v.size())
        {
            if(v[i].deg == 0) cnt++;
            if(v[i].deg == 1)  //leaf node it is, in this case its XOR is the other end of edge
            {
                tree_edge.x1= i;
                tree_edge.x2= v[i].s;
                v[i].deg=0;

                // cout<<tree_edge.x1<<" "<<tree_edge.x2<<endl;

                tree.pb(tree_edge);

                v[v[i].s].deg -=1;
                v[v[i].s].s= v[v[i].s].s ^ i;
            }

        }

        if(cnt==n)return;

    }
}

int main() {

    cin>>n;

    ll deg, s;
    str s1;
    FOR(i, n)
    {
        cin>>s1.deg>>s1.s;
        v.pb(s1);
    }

    maketree();
    cout<<tree.size()<<endl;
    FOR(i, tree.size()) cout<<tree[i].x1<<" "<<tree[i].x2<<endl;

    return 0;
}
