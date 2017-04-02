#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int main() {

    int q;
    cin>>q;
    while(q--)
    {
        int r, p, n, m;
        cin>>r>>p>>n>>m;

        int present[m];
        FOR(i, m) cin>>present[i];

        int cost[p];
        FOR(i, p) cin>>cost[p];

        int book[r][p], temp;
        FOR(i, r)
        {
            FOR(j, p)
            {
                cin>>temp;
                book[i][j]= temp;
            }
        }

        int super[p];
        FOR(i, p) super[i]= i;

        map<int, int> dishSum;
        int *availIngre;
        availIngre= diffArray(p, present);

    }

    return 0;
}
