#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    int n; cin>>n;
    string s, str="", temp;

    set<string> stringSet;
    set<string>::iterator it;

    getline(cin, temp);
    FOR(i, n)
    {
        getline(cin, s);
        str= s+ " " + str;
    }

    FOR(i, str.length())
    {
        str[i]= tolower(str[i]);
        if(ispunct(str[i])) str[i]= ' ';
    }

    char* token;
    char *dup= strdup(str.c_str());
    token= strtok(dup, " ");
    while(token != NULL)
    {
        stringSet.insert(token);
        token= strtok(NULL, " ");
    }
    free(dup);

    cout<<stringSet.size()<<endl;
    for(it= stringSet.begin(); it!= stringSet.end(); ++it)
        cout<<*it<<endl;

    return 0;
}

