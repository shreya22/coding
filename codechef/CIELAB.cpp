#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    int b, a;
    cin>>b>>a;
    int x= b-a;
    x= x/10;

    cout<<x*10+1;

    return 0;
}
