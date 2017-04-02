#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int n;
vector<int> v[100001];
ll w[100001];  //weight on each node
ll ew[100001]; //weight on edge

int cnt=0;
void dfs(int root, ll sum)
{
    if(sum > w[root]) return;
    cnt++; //cout<<root<<endl;

    FOR(i, v[root].size())
    {
        if(sum<0) sum=0;
        //cout<<"from "<<root<<" to "<<v[root][i]<<" with sum "<<sum+ew[v[root][i]]<<endl;
        dfs(v[root][i], sum+ ew[v[root][i]]);
    }
}

int main() {

    cin>>n;

    FOR(i, n) cin>>w[i+1];

    ll index, weight;
    FOR1(i, n)
    {
        cin>>index>>weight;
        v[index].pb(i+1);
        ew[i+1]= weight;
    }

    dfs(1, 0); // 1->root, 0->cost till now
    cout<<n-cnt;

    return 0;
}
