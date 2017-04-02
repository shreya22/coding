#include <bits/stdc++.h>
#include <iterator>
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
        ll n, temp;
        multiset<ll> ms;
        vector<ll> v;

        cin>>n;
        FOR(i, n){
            cin>>temp;
            ms.insert(temp);
        }

        multiset<ll>::iterator it;

        for(it= next(ms.begin(),1);  it!= ms.end(); ++it){
            v.pb( abs( (*it - *prev(it, 1)) ) );
        }

        ll min=1000000000;
        FOR(i, v.size()){
            if(v[i] < min) min= v[i];
        }

        cout<<min<<endl;

    }

    return 0;
}
