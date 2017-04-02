#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int flip(int x)
{
    if(x==1) return 2;
    return 1;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int g, i, n, q;
        cin>>g;

        vector<int> v;
        for(int s=0; s<g; ++s)
        {
            cin>>i>>n>>q;
            if(s==0){
                // intialize vector
                FOR(i, n) v[i]= i;
            }

            if(n%2== 0){
                for(int x= 1; x<n; x+=2) v[x]= flip(v[x]);
            }else{
                for(int x= 0; x<n; x+=2) v[x]= flip(v[x]);
            }

            long cnt=0;
            FOR(x, n){
                if(v[x] == q) cnt++;
            }
            cout<<cnt<<endl;
        }


        // while(g--)
        // {
        //     int i, q; long n, flag;
        //     cin>>i>>n>>q;

        //     vector<int> v(n, i);

        //     flag= (i==1)?2:1;
        //     if(n%2== 0){
        //         for(int x= 1; x<n; x+=2) v[x]= flag;
        //     }else{
        //         for(int x= 0; x<n; x+=2) v[x]= flag;
        //     }

        //     long cnt=0;
        //     FOR(x, n){
        //         if(v[x] == q) cnt++;
        //     }
        //     cout<<cnt<<endl;
        // }
    }

    return 0;
}
