#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back

int n, k, d;
#define MAX 1000000007
int cnt=0;  //how many such paths possible
vector< vector<int> > v(101, vector<int>(101));

void dfs(int init, int sum, int flag)  //init->current node, sum->sum till now, flag=1 => threshold crossed
{
    if(sum==n && flag==1){
        cnt++;
        cnt%=MAX;
        return;
    }

    if(sum < n){
        FOR(i, k)
            if(flag == 0)
                dfs(v[init][i], sum+i+1, (i+1>=d?1:0));
            else
                dfs(v[init][i], sum+i+1, 1);
    }

    return;
}

int main() {

    cin>>n>>k>>d;
    FOR(i, k)   //initialising nxn vector with values from 0 to k-1
        FOR(j, k)
            v[i].pb(j+1);

    dfs(0, 0, 0);
    cout<<cnt;

    return 0;
}
