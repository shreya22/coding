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

    vector<float> a(n);

    int temp;
    FOR(i, n){
        cin>>temp;
        a[i]= temp;
    }

    int totpgcount=0;
    int splcount=0;
    int num_pages=0;

    FOR(i, n)
    {
        num_pages= ceil(a[i]/k);   //number of pages in this chapter

        cout<<"num_pages "<<num_pages<<" ";

        int queno=1;
        //iterate through each page, find out for special num
        for(int i=totpgcount+1; i<=totpgcount+num_pages; ++i)
        {
            if(i == totpgcount+num_pages)
            {
                if((i >= queno) && (i < queno+ (int)a[i]%k))
                {cout<<"oo"<<a[i]<<"oo";
                    splcount++;
                    break;
                }
            }

            if((i >= queno) && (i < queno+k))
            {
                splcount++;
            }

            queno+= k;

        }

        totpgcount+= num_pages;
        cout<<splcount<<" ";
    }
cout<<endl;
    cout<<splcount;

    return 0;
}
