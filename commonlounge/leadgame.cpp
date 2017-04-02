#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {


    int n;
    cin>>n;
    int a, b, lead=0, player= 1;

    FOR(i, n)
    {
        cin>>a>>b;
        if(abs(a-b)>lead){

            lead= abs(a-b);
            if(a>b) player= 1;
            else player=2;
        }
    }
    cout<<player<<" "<<lead;

    return 0;
}
