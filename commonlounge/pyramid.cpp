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

    int m;
    cin>>m;
    int count=0;
    int arr[m];

    int x, y;
    FOR(i, m){
        cin>>x>>y;
        arr[i]= min(x, y);
    }

    sort(arr, arr+m);

    int index=0;
    while(index<m){
        if(arr[index] > count) count++;
        index++;
    }

    cout<<count;

    return 0;
}
