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

    int n, q;
    cin>>n>>q;

    vector<vector<int>> v(n);
    vector<vector<int>>::iterator it;

    long flag, x, y;
    int lastans=0, index;

    FOR(i, q){
        cin>>flag>>x>>y;

        if(flag == 1){
            index= (x^lastans)%n;
            v[index].push_back(y);

        }else{
            index= (x^lastans)%n;
            lastans= v[index][y%v[index].size()];

            cout<<lastans<<endl;
        }
    }


    return 0;
}
