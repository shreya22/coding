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

    vector<vector<int>> a(6, vector<int>(6));
    FOR(i, 6)
        FOR(j, 6)
            cin>>a[i][j];

    int sum=-63, temp;

    FOR(i, 4)
    {
        FOR(j, 4)
        {
            temp= a[i][j]+ a[i][j+1] + a[i][j+2] + a[i+1][j+1] + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
            sum= max(sum, temp);
        }
    }
    cout<<sum;


    return 0;
}
