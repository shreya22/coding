// The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence
// of a given sequence such that all elements of the subsequence are sorted in increasing order.
// For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.

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

int lis(int arr[], int n)
{
    int lis[n];
    fill_n(lis, n, 1); //initializing an array to a default value!
    FOR(i, n)
        for(int j=0; j<i; ++j)
            if(arr[i]>arr[j] && lis[i]<lis[j]+1) lis[i]= lis[j]+1;

    int max= 1;
    FOR(i, n) if(max < lis[i]) max= lis[i];

    return max;
}

int main() {

    int n;
    cin>>n;

    int arr[n];
    FOR(i, n) cin>>arr[i];

    cout<<"length of lis "<<lis(arr, n);

    return 0;
}
