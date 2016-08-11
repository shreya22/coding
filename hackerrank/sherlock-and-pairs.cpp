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

    int t;
    cin>>t;
    while(t--)
    {
        int n, temp;
        cin>>n;

        int a[n], count[n];
        FOR(i, n) cin>>a[i];
        sort(a, a+n);

        long cnt=1, c=0;
        FOR1(i, n)
        {
            if(a[i] == a[i-1]) cnt++;
            else
            {
                count[c++]= cnt;
                cnt=1;
            }
        }
        count[c++]= cnt;

        cnt=0;
        FOR(i, c)
        {
            cnt+= count[i]*(count[i]-1);
        }
        cout<<cnt<<endl;
    }

    return 0;
}
