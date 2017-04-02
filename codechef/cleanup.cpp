#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        // int m, n, temp;
        // cin>>m>>n;
        // set<int> s1, s2;
        // set<int>::iterator it1= s1.begin(), it2= s2.begin();

        // FOR(i, m) {
        //     cin>>temp;
        //     s1.insert(temp);
        // };
        // FOR(i, n) s2.insert(i+1);

        // int flag=0;
        // vector<int> chef, ass;

        // for(it1= s1.begin(); it1!=s1.end(); it1++)
        // {
        //     if(*it1 == *it2) it2++;
        //     else {
        //         if(flag == 0){
        //             chef.pb(*it1);
        //             flag=1;
        //         }else {
        //             ass.pb(*it2);
        //             flag=0;
        //         }
        //     }
        // }

        int m, n, temp;
        cin>>n>>m;

        set<int> s1, s2;
        FOR(i, m){
            cin>>temp;
            s1.insert(temp);
        }
        FOR(i, n) s2.insert(i+1);

        set<int>::iterator it1= s1.begin(), it2= s2.begin();

        vector<int> chef, ass;
        int flag=0;

        for(it2= s2.begin(); it2!= s2.end(); it2++)
        {
            if(*it2 == *it1) it1++;
            else{
                if(flag==0){
                    chef.pb(*it2);
                    flag=1;
                }else{
                    ass.pb(*it2);
                    flag=0;
                }
            }
        }

        if(chef.size() == 0) cout<<endl;
        else FOR(i, chef.size()) cout<<chef[i]<<" ";

        cout<<endl;

        if(ass.size() == 0) cout<<endl;
        else FOR(i, ass.size()) cout<<ass[i]<<" ";
    }


    return 0;
}
