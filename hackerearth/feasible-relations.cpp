#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 1000001

int n, k;
vector<int> parent;
int a[MAX], b[MAX];
string rel[MAX];

int get(int x)
{
    if(parent[x] == x) return x;
    return get(parent[x]);
}

void merge(int x, int y)
{
    int a, b;
    a= get(x);
    b= get(y);

    parent[a]= b;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;

        parent.clear();
        parent.pb(-1);
        FOR1(i, n+1) parent.pb(i);

        // string rel[n+1];
        FOR1(i, k+1)
        {
            cin>>a[i]>>rel[i]>>b[i];
            if(rel[i] == "=")
                merge(a[i], b[i]);
        }

        int error=0;
        FOR1(i, k+1)
        {
            if(rel[i] == "=") continue;

            if(get(a[i]) == get(b[i])) error=1;
            else error=0;

            if(error==1) break;
        }

        if(error) cout<<"NO\n";
        else cout<<"YES\n";


    }

    return 0;
}
