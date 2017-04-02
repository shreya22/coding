#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define l long

float n, d, r, x, y;
float dis;

int main() {

    cin>>n>>d>>r;
    float cnt=0.0000;
    FOR(i, n){
        cin>>x>>y;

        dis= sqrt(pow(x, 2) + pow(y, 2));
        if(dis<= r+d) cnt+=1;
    }

    printf("%.4lf", cnt);

    return 0;
}
