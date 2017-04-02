#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int max(int a, int b){
    return (a>b)?a:b;
}

int min(int a, int b){
    return (a<b)?a:b;
}

void swap(int *a, int *b){
    var temp;
    temp= *a;
    *a= *b;
    *b= temp;
}

int main() {

    int n, k;
    cin>>n>>k;
    int arr1[n], arr2[n];

    FOR(i, n) cin>>arr1[i];
    FOR(i, n) cin>>arr2[i];

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    int val1, val2, val3, minVal=0, maxVal;
    maxVal= max(arr1[n-1], arr2[n-1]);
    FOR(i, k)
    {
        val1= arr1[n-1] + arr2[n-1]; cout<<val1<<endl;
        val2= maxVal + max(arr1[0], arr2[n-2]); cout<<val2<<endl;
        val3= maxVal + max(arr1[n-2], arr2[0]); cout<<val3<<endl;

        minVal= min(val1, min(val2, val3));
        if(minVal == val1) break;

        if(minVal== val1) swap(arr1[0], arr2[n-1]);
        else swap(arr[0], arr1[n-1]);

        sort(arr1, arr1+n);
        sort(arr2, arr2+n);
    }

    cout<<minVal;
    return 0;
}
