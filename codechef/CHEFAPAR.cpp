#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int a[n], temp= n, cnt=0, flag=0;
        FOR(i, n)
        {
            cin>>a[i];
            if(flag == 0 && a[i]==0)
            {
                temp= i;
                flag= 1;
            }

            if(a[i]== 1) cnt++;
        }
        cout<<(n-temp)*100 + (n-cnt)*1000<<endl;
    }

    return 0;
}
