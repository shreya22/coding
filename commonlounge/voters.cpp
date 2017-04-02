#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

map<int, int> store;
void makeMap(int n)
{
    FOR(i, n)
    {
        int temp;
        cin>>temp;
        if(store.find(temp) == store.end()) store.insert(pair<int, int>(temp, 1));
        else store[temp]= store[temp]+1;
    }
}

int main() {

    int n1, n2, n3;
    cin>>n1>>n2>>n3;

    makeMap(n1);
    makeMap(n2);
    makeMap(n3);

    map<int, int>::iterator it= store.begin();
    int count=0;

    for(it=store.begin(); it!= store.end(); it++)
        if(it->second >=2) count++;

    cout<<count<<endl;
    for(it=store.begin(); it!= store.end(); it++){
        if(it->second >=2) cout<<it->first<<endl;
    }

    return 0;
}
