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

void fun(int r, int c){
    FOR(i, r){
        FOR(j, c) cout<<"..O.."; cout<<endl;
        FOR(j, c) cout<<"O.o.O"; cout<<endl;
        FOR(j, c) cout<<"..O.."; cout<<endl;
    }
}

int main() {

    int r, c; cin>>r>>c;
    fun(r, c);

    return 0;
}
