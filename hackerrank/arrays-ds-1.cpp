#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <cctype> //toupper, tolower
#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)

int main() {

    int n, temp;
    cin>>n;

    vector<int> a(n);
    FOR(i, n) cin>>a[i];

    FOR(i, n/2){
        temp= a[i];
        a[i]= a[n-i-1];
        a[n-i-1]= temp;
    }

    FOR(i, n) cout<<a[i]<<" ";

    return 0;
}
