#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define pb push_back;
#define ll long long

void printPerm(string prefix, string left){
    if(left.length()){
        FOR(i, left.length())
            printPerm(prefix+left[i], left.substr(0, i)+left.substr(i+1));
    }else
        cout<<prefix<<endl;
}

int main(){
    int n;
    cin>>n;
    string str="";
    FOR1(i, n+1) str+= char(i+48);
    
    printPerm("", str);


    return 0;
}