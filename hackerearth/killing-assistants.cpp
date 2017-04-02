#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int HCF(int a, int b){
    if(b==0) return a;
    HCF(b, a%b);
}

int main() {

    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int num= 9*m;
        int den= 9*m + 8*(n-m);

        int hcf= HCF(den, num);

        num /= hcf;
        den /= hcf;
        cout<<num<<"/"<<den<<endl;
    }

    return 0;
}
