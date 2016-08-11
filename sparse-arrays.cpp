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

    map<string, int> a;
    string str;
    int n;

    cin>>n;
    FOR(i, n)
    {
        cin>>str;
        if(a.find(str) == a.end())
        {
            //not present in list, new insertion
            a.insert(pair<string, int>(str, 1));
        }else{
            //present in list, increment count
            a[str] += 1;
        }
    }

    int q;
    cin>>q;
    FOR(i, q)
    {
        cin>>str;
        if(a.find(str) == a.end()) cout<<"0\n";
        else
        {
            cout<<a[str]<<endl;
        }
    }

    return 0;
}
