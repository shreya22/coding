#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

long min(long a, long b){
    return (a>b)?b:a;
}

int main() {

    char s[1001];
    cin.getline(s, 1001);

    cout<<s[0];
    FOR1(i, strlen(s)){
        if(s[i+1]!='\0'){
            if(s[i]== ' ') cout<<s[i+1];
        }
    }

    return 0;
}
