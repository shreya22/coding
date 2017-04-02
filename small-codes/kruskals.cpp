#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 100000

int n, e, minWeight=0;
vector<int> parent(MAX);
int head[MAX];

struct edge{
    int start, end, weight;
};

vector<edge> v;
vector< pair<int, int> > ans(MAX);

int findParent(int x)
{
    if(parent[x] == x) return x;
    return findParent(parent[x]);
}

void join(int a, int b)
{
    if(head[a] > head[b]) parent[b]= a;
    else if (head[b] > head[a]) parent[a]= b;

    else{
        parent[b]= a;
        head[a]++;
    }
}

bool customsort(edge i, edge j)
{
    return i.weight < j.weight;
}

void kruskals()
{
    sort(v.begin(), v.end(), customsort);

    FOR(i, e)
    {
        int px= findParent(v[i].start);
        int py= findParent(v[i].end);

        if(px != py)
        {
            join(px, py);
            ans.pb(pair<int, int>(v[i].start, v[i].end));

            minWeight+= v[i].weight;
        }
    }
}

int main() {

    cin>>n>>e;

    FOR(i, n){
        parent[i]= i;
        head[i]= 0;
    }

    int x, y, w;
    FOR(i, e)
    {
        edge temp;
        cin>>x>>y>>w;

        temp= {x, y, w};
        v.pb(temp);
    }


    kruskals();
    cout<<minWeight<<endl;

    return 0;
}
