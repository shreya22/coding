#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

void swap(ll *a, ll *b)
{
    ll temp;
    temp= *a;
    *a= *b;
    *b= temp;
}

int partition(ll a[], int n, int k)
{
    swap(&a[k], &a[n]);

    int x=0, y=1, val;

    val= a[n];
    FOR1(y, n)
    {
        if(a[y] <= val){
            x++;
            swap(&a[x], &a[y]);
        }
    }
    return x+1;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int k, n;
        cin>>n;

        ll a[n+1];

        a[0]= -1;
        FOR1(i, n+1) cin>>a[i];
        cin>>k;

        cout<<partition(a, n, k)<<endl;
    }

    return 0;
}
