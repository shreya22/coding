#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

void leftSwap(int* a){
   int temp;
   temp= a[0];
   a[0]= a[1];
   a[1]= temp;
}

int main() {

    long n;
    int x;

    cin>>n>>x;

    int order[3]= {0, 1, 2};
    int ls; // no of leftshifts

    ls= ((n%2==0)?n/2:(n-1)/2)%3;

    if(ls==1){
        order[0]= 1; order[1]= 2; order[2]= 0;
    }
    else if(ls == 2) {
        order[0]= 2; order[1]= 0; order[2]= 1;
    }
    else;

    int *a;
    if(n%2==1) leftSwap(order);
    cout<<order[x];

    return 0;
}
