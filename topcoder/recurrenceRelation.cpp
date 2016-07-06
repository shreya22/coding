#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <cctype> //toupper, tolower
#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)

int temp;
int len; //num of elements in array

int recc(int coff[], int val[], int n){
    if(n==1) return val[len-1];

    temp=0;
    FOR(i, len) temp+= coff[i]*val[i];

    FOR(i, len-1) val[i]= val[i+1];
    val[len-1]= temp;

    cout<<temp<<" ";

    recc(coff, val, --n);
}

int main() {
    cin>>len;

    int val[len]; //store initial values input
    int coff[len]; //store coefficient input
    int n; //we have to find value at this
    int xn; //our final answer

    FOR(i, len) cin>>coff[i];
    FOR(i, len) cin>>val[i];

    cin>>n;

    cout<<recc(coff, val, n)%10;

    return 0;
}
