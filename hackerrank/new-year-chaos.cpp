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

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a(n), b(n);
        int temp;
        FOR(i, n){
            cin>>temp;
            a[i]= temp;
            b[i]= temp;
        }

        int numcount=0; //stores number of times we need to swap in order to get sorted string
        int tmp=0; //temporary storage

        FOR(i, n)
        {
            for(int j=tmp; j<(n-1); ++j)
            {
                if(a[j]>a[j+1])
                {
                    swap(a[j], a[j+1]);
                    numcount++;

                    tmp= j+1;
                    break;
                }
            }

            if(a==b)break;
        }
        cout<<

    }

    return 0;
}
