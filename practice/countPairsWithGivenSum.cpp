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

int main() {

    int n, sum;
    cin>>n>>sum;

    int arr[n];
    FOR(i, n) cin>>arr[i];

    int p=0, q= n-1, count=0;
    sort(arr, arr+n);

    int temp;
    while(p<q){
        temp= arr[p] + arr[q];
        if(temp == sum) {
            p++; q--;
            count++;
        }
        else if(temp<sum) p++;
        else q--;
    }

    cout<<count;
    return 0;
}
