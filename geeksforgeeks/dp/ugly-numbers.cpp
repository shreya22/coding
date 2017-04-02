#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int x, int y, int z)
{
    return (x< (y<z)?y:z ): x ? (y<z)?y:z;
}

int printUglyNumber(int n)
{
    int p=1, q=1, r=1, arr[n+1];

    arr[0]= 1;
    FOR1(i, n)
    {
        int min= minimum(pow(2, p), pow(3, q), pow)
    }
}

int main() {

    int n;
    cin>>n;
    cout<<printUglyNumber(n);

    return 0;
}
