#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <cctype> //toupper, tolower
#include <vector>
#include <cstdio>
#include <array>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)

int main() {

    int n;
    cin>>n;

    array<long, 1000000> a, b;
    FOR(i, n){
        cin>>a[i];
        b[i]= a[i];
    }

    sort(b, b+n);

    int start=-1, end=-1;
    FOR(i, n){
        if(a[i] != b[i]){
            start= i;
            break;
        }
    }

    FORrev(i, n){
        if(a[i] != b[i]){
            end= i;
            break;
        }
    }

    if(start == -1 && end == -1) cout<<"yes";
    else{
        swap(start, end);
        if(a == b) cout<<"yes"<<endl<<"swap "<<start+1<<" "<<end+1;
        else{
            for(int i=start; i<=(end-start)/2+start; ++i)
                swap(a[i], a[end-i + start]);
            if(a == b) cout<<"yes"<<endl<<"reverse "<<start+1<<" "<<end+1;
            else
                cout<<"no";
        }
    }

    return 0;
}
