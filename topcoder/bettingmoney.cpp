#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)

int main() {

    int amounts[51], centsperdollar[51];

    int n; //no of elements in amounts/centsperdollar
    int final; //final reuslt of the match
    int profit=0; //total money the company will earn

    cout<<"enter num of elements in amounts ";
    cin>>n;

    cout<<"enter "<<n<<" amounts";
    FOR(i, n){
        cin>>amounts[i];
    }

    cout<<"enter "<<n<<" centsperdollar";
    FOR(i, n) cin>>centsperdollar[i];

    cout<<"enter final score";
    cin>>final;

    FOR(i, n){
        if(i != final)
            profit+= 100*amounts[i];
    }

    profit-= centsperdollar[final]*amounts[final];
    cout<<profit;

    return 0;
}
