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

    int n, k;

    cin>>n>>k;
    vector<int> a(n);

    int temp;
    FOR(i, n)
    {
        cin>>temp;
        a[i]= temp;
    }

    k= k%n;
    int cnt=100;
    int pos=0;

    FOR(i, n){
        pos= (pos+k)%n;
        if(a[pos] == 1) cnt-=2;
        cnt--;

        if(pos == 0)break;
    }
    cout<<cnt;

    return 0;
}
