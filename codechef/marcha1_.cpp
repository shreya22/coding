#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int n, totalsum;

bool output(vector<int> val)
{
    int sum;
        FOR(i, pow(2, n))
        {
            sum=0;
            FOR(j, n)
            {
                if(i & (1<<j)) sum+= val[j];
            }
            if(sum == totalsum) return true;
        }
        return false;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>totalsum;

        vector<int> v(n+1);
        FOR(i, n) cin>>v[i];

        if(output(v)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
