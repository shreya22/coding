#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define MAX 10001
int ind=-1;

int maxSpeedCars(int start, int end, int a[])
{
    int min= MAX;

    if(start >= end) return 1;
    for(int i=start; i<=end; ++i)
    {
        if(a[i]<min){
            min= a[i];
            ind= i;
        }
    }
    return 1+ maxSpeedCars(start, ind, a);
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int speed[n];
        FOR(i, n) scanf("%d", &speed[i]);

        cout<<maxSpeedCars(0, n-1, speed)<<endl;
    }

    return 0;
}
