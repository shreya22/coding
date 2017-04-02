#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
int a[100000];

int binarySearch(int low, int high, int x)
{
    while(low<=high){
        int mid= (low+high)/2;
        if(x<a[mid]) high=mid-1;
        else if(x>a[mid]) low=mid+1;
        else return mid+1;
    }
    return -1;
}

int main() {

    int n, q;
    cin>>n;

    FOR(i, n)cin>>a[i];
    sort(a, a+n);

    cin>>q;
    long temp;
    FOR(i, q){
        cin>>temp;
        cout<<binarySearch(0, n-1, temp)<<endl;
    }

    return 0;
}
