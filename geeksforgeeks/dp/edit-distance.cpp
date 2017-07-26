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

int editDistance(string a, string b){
    int l1= a.length(), l2= b.length();
    int arr[l1+1][l2+1];

    FOR(i, l1+1) arr[i][0]= i;
    FOR(j, l2+1) arr[0][j]= j;

    FOR1(i, l1+1){
        FOR1(j, l2+1){
            if(a[i-1] == b[j-1]) arr[i][j]= arr[i-1][j-1];
            else arr[i][j]= min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1])) +1;
        }
    }

    return arr[l1][l2];
}

int main() {

    string a, b;
    cin>>a;
    cin>>b;

    cout<<"min no of operation required: ";
    cout<<editDistance(a, b)<<endl;

    return 0;
}
