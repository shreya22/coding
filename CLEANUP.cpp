#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int m, n, temp;
        set<int> s1, s2;

        cin>>temp;
        FOR(i, m) s1.insert(temp);
        FOR(i, n) s2.insert(i+1);

        FOR(i, n) cout<<s2[i]<<" ";
    }


    return 0;
}
