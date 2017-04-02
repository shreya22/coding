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

    long n, k;
    vector<long> v;
    long temp;

    cin>>n>>k;
    for(long i=0; i<n; ++i) {
        cin>>temp;
        v.pb(temp);
    }
    sort(v.begin(), v.begin()+n);

    long i1=0;

    long long count=0;
    for(long i=0; i<n; ++i){
        for(long j= i1; j<n; ++j)
            if(v[j]- v[i] >=k){
                i1= j;
                count+= n-j;
                break;
            }
    }

    cout<<count;

    return 0;
}
