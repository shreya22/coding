#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <cctype> //toupper, tolower
#include <vector>
#include <cstdio>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)

int main() {

    int n;
    cin>>n;

    vector<int> a(n);

    int cnt=0, maxcnt=0, temp, x;
    FOR(i, n){
        cin>>x; a[i]=x;
    }

    //FOR(i, n) cout<<a[i]<<" ";

    FOR(i, n)
    {
        temp= i;
        while(a[temp] != -1)
        {
            cnt++;
            temp = a[temp]-1;
        }
        maxcnt= max(maxcnt, cnt);
        // cout<<maxcnt<<" ";

        cnt=0;
    }
    cout<<maxcnt+1;

    return 0;
}
