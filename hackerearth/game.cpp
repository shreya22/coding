#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
int n, q;

int maxDepth(vector< vector<int> > v, int x, int y)
{
    stack<long> s;

    long temp= n*x+y;
    int p, q, depth=0;

    s.push(temp);
    while(s.size()){
        temp= s.top();
        s.pop();
        p= temp/n; q= temp%n;

        // cout<<p<<" "<<q<<endl;
        // cout<<"p+1 "<<p+1<<endl;


        if(p+1 < n)
        {
            if((v[p+1][q-1] || v[p+1][q] || v[p+1][q+1]) && depth == p) {
                // cout<<p<<" "<<q<<" "<<depth<<endl;
                depth++;
            }

            if(v[p+1][q-1] == 1) s.push(n*(p+1)+(q-1));
            if(v[p+1][q] == 1) s.push(n*(p+1)+(q));
            if(v[p+1][q+1] == 1) s.push(n*(p+1)+(q+1));


        }
    }

    return depth;
}

ll max(int a, int b)
{
    return (a>b)?a:b;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;

        vector< vector<int> > v(n, vector<int>(3, 1));

        int x, y;
        FOR(i, q)
        {
            cin>>x>>y;
            v[x-1][y-1]= 0;
        }

        int a= maxDepth(v, 0, 0) +1;
        int b= maxDepth(v, 0, 1) +1;
        int c= maxDepth(v, 0, 2) +1;

        cout<<max(a, max(b, c))<<endl;

        // FOR(i, n)
        // {
        //     FOR(j, 3)
        //         cout<<v[i][j]<<" ";
        //     cout<<endl;
        // }
    }

    return 0;
}
