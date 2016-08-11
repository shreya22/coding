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

    int n, k;
    cin>>n>>k;

    vector<long> a(k);
    int temp;
    FOR(i, n)
    {
        cin>>temp;
        a[temp%k]++;
    }

    long sum=0;
    if(k%2 == 0)
    {
        FOR1(i, k/2)
            sum+= (a[i]>a[k-i]?a[i]:a[k-i]);

        if(a[k/2]!=0) sum++;
    }else{
        FOR1(i, (k/2) + 1)
            sum+=(a[i]>a[k-i]?a[i]:a[k-i]);
    }

    if(a[0]!=0 || sum==0) sum++;
    cout<<sum;

    return 0;
}
