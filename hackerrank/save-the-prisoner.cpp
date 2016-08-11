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
    while(t--){
        long n, m, s;
        cin>>n>>m>>s;
        long temp, id;

        if(m%n == 0){
            if(s == 1) cout<<n;
            else cout<<s-1;
        }else{
            if((s+m-1)%n == 0) cout<<n;
            else cout<<(s+m-1)%n;
        }

        cout<<endl;
    }

    return 0;
}
