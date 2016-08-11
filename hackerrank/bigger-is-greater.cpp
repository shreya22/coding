#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <cctype> //toupper, tolower
#include <vector>
#include <cstdio>
#include <set>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)

int main() {

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        vector<char> vec(s.length());
        vector<string>::iterator it;

        FOR(i, s.length()) vec[i]= s[i];

        int flag=-1;
        FORrev(i, vec.size()-1)
        {
            if(vec[i] < vec[i+1])
            {
                flag= i;
                break;
            }
        }

        char tmp;
        int x;

        if(flag == -1) cout<<"no answer\n";
        else{
            tmp= vec[flag]; //cout<<flag<<endl;

            FOR(i, flag) cout<<vec[i]; //cout<<endl;
            sort(vec.begin()+flag, vec.begin()+vec.size());

            //print the term next to pivot in sorted vector list
            for(int i= flag; i<vec.size(); ++i)
            {
                if(vec[i] == tmp && vec[i+1]!=tmp){
                    cout<<vec[i+1];
                    x= i+1; //cout<<x<<endl;
                    break;
                }
            }

            for(int i= flag; i<vec.size(); ++i)
            {
                if(i != x) cout<<vec[i];
            }
            cout<<endl;

        }
    }

    return 0;
}
