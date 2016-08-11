#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    string buffer;
    stringstream ss1(s1);
    stringstream ss2(s2);

    vector<string> sen1, sen2;
    while(ss1 >> buffer) sen1.pb(buffer);
    while(ss2 >> buffer) sen2.pb(buffer);

    int cnt=0;
    FOR(i, sen2.size())
    {
        if(sen2[i][0] != '{') cout<<sen2[i]<<" ";
        else
        {
            if(sen2[i][1] == '}')   cout<<sen1[cnt++]<<" ";
            else cout<<sen1[(int)sen2[i][1]-48]<<" ";
        }
    }

    return 0;
}
