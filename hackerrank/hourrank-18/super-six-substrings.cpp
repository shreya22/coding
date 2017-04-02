#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

string s;
ll memoize[100002][5];

ll fun(int i, int m)
{
    if(i== s.length()) return 0;
    if(memoize[i][m] != -1) return memoize[i][m];

    int x= s[i] - '0';
    int temp= fun(i+1, )
}

int main() {

    memset(memoize, -1, sizeof memoize);
    long long count=0;
    cin>>s;

    FOR(i, s.length())
    {
        if(s[i]== '0')count++;
        else count += fun(i, 0);
    }

    return 0;
}
