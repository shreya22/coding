#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back

int cnt=0; //num of restaurent we can visit
int cat[100001]= {};     //if 1, cat present, else no
int visited[100001]= {};
vector<int> tree[100001];   //stores tree, v[i].size() => i is parent of this many nodes

int n, m;

void dfs(int init, int catnum)
{
    // return if no of cats>m or this node is visited
    if(visited[init] || cat[init]+catnum>m) return;

    visited[init]= 1; //node visited

    if(cat[init]) catnum+=1;
    else catnum=0;

    if(tree[init].size()==1 && init!=1) cnt++;    //means its a leaf node
    FOR(i, tree[init].size())
        dfs(tree[init][i], catnum);

    return;

}

int main() {
    cin>>n>>m;



    int temp;
    FOR1(i, n+1){
        cin>>temp;
        cat[i]= temp;
    }

    int x1, x2;
    FOR(i, n-1)
    {
        cin>>x1>>x2;
        tree[x1].pb(x2);
        tree[x2].pb(x1);
    }

    dfs(1, 0); // 1=> starting node, 0=>num of cats till now
    cout<<cnt;

    return 0;
}
