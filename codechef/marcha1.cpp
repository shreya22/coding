#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

bool subsetSum(int val[], int n, int m)
{
    bool arr[21][20001];

    // initialization
    // sum> 0 and n==0 => FALSE, sum=0 TRUE
    FOR(i, n+1) arr[i][0] = true;
    FOR1(j, m+1) arr[0][j] = false;

    FOR1(i, n+1)
        FOR1(j, m+1)
        {
            arr[i][j]= arr[i-1][j];
            if(j >= val[i]) arr[i][j]= arr[i][j] || arr[i-1][j-val[i]];
        }

    return arr[n][m];
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n, m; // n- no of notes, m-money demanded
        cin>>n>>m;

        int val[n+1];
        val[0]= 0;
        FOR1(i, n+1) cin>>val[i];

        bool out= subsetSum(val, n, m);
        if(out) cout<<"Yes\n";
        else cout<<"No\n";

    }

    return 0;
}
