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

    int n;
    cin>>n;
    int a[n];
    FOR(i, n) cin>>a[i];
    sort(a, a+n);

    int p, q, temp, current;
    long count=0;
    FOR(i, n)
    {
        current= a[i];
        p=0, q=n-1;
        while(p<q){

            temp= (a[p] + a[q])/2;
            if((temp == current) && (a[p]+a[q])%2 == 0) {
                count++; p++; q--;
            }
            else if(temp < current) p++;
            else q--;

            if(a[p] > current) break;
        }
    }
    cout<<count;

    return 0;
}
