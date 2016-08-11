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
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)

int main() {

    int n, cnt;
    cin>>n>>cnt;

    int a[n], b[n];
    FOR(i, n) cin>>a[i];

    FOR(i, n)
    {
        temp= i-cnt;
        if(temp < 0) temp= n+temp;

        b[temp]= a[i];
    }
    FOR(i, n) cout<<b[i]<<" ";

    return 0;
}
