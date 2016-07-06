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

int main() {

    int n, k, q;
    cin>>n>>k>>q;

    int a[n], b[n], queries[q];

    if(k>n) k= k%n;

    FOR(i, n) cin>>a[i];

    int temp=0, temp2=0; //helper variable

    FOR(i, n){
        temp= i+k;
        if(temp > (n-1)) temp-= n;

        b[temp]= a[i];
    }

    FOR(i, q){
        cin>>queries[i];
        cout<<b[queries[i]]<<endl;
    }

    return 0;
}
