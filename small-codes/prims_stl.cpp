#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 100001


int n, e;
int tree[MAX][MAX];
int parent[MAX], key[MAX];
bool mst[MAX]; //store vertices left to be included in mst, <key, index>

void maketree()
{
    cin>>e;
    int s, d, wt;
    FOR(i, e)
    {
        cin>>s>>d>>wt;
        tree[s][d]= wt;
        tree[d][s]= wt;
    }
}

int findmin()
{
    int min_val= MAX, min_index;
    FOR(i, n){
        if(mst[i]==false && key[i]<min_val)
        {
            min_val= key[i];
            min_index= i;
        }
    }
    return min_index;
}

// void printmst()
// {
//     FOR1(i, n+1) cout<<parent[i]<<" "<<i<<" with weight"<<key[i]<<endl;
// }

void prims(int root)
{
    key[root]= 0;

    FOR(i, n-1)
    {
        int u= findmin();
        mst[u]= true;

        FOR(v, n)
        {
            if(tree[u][v] && mst[v]==false && tree[u][v]<key[v])
                parent[v]=u, key[v]=tree[u][v];
        }
    }

    // printmst();

}

int main() {

    cin>>n;
    FOR(i, n) {
        parent[i]= -1;
        key[i]= MAX;
        mst[i]= false;
    }

    maketree();

    prims(1);

    return 0;
}
