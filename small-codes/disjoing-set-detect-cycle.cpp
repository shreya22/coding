#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 100000

int n, e;
vector<int> parent(MAX), rank(MAX);

int findParent(int x)
{
    if(parent[x] == x) return x;
    return findParent(parent[x]);
}

void join(int a, int b)
{
    if(rank[a] > rank[b]) parent[b]= a;
    else if (rank[b] > rank[a]) parent[a]= b;

    else{
        parent[b]= a;
        rank[a]++;
    }
}

int main() {

    cin>>n>>e;

    FOR1(i, n+1) parent[i]= i;
    fill(rank.begin(), rank.begin()+n+1, 0);

    int x, y, cnt=0;
    FOR(i, e)
    {
        cin>>x>>y;

        int px= findParent(x);
        int py= findParent(y);

        if(px == py) cnt++;
        else{
            join(px, py);
        }
    }

    cout<<cnt<<" cycles found!\n";


    return 0;
}
