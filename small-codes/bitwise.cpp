#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back

int main() {

    int x, y;
    cin>>x>>y;

    int p= x ^ y;
    cout<<p;

    return 0;
}
