#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define l long

struct str
{
    int y;
    int val;
};

int main() {

    l q;
    cin>>q;
    multiset<int> multi;
    multiset<int>::iterator it, it1;
    map<int, str> check;

    char c; int x, maxval, temp=0;
    while(q--)
    {
        cin>>c>>x;
        switch(c){
            case '+':
                multi.insert(x);
;                break;
            case '-':
                it= multi.find(x);
                it1= it;
                it1++;
                multi.erase(it, it1);
                break;
            default:
                if(check.find(x) != check.end()){
                    if(multi.find(check[x].y) != multi.end()){
                        cout<<check[x].val<<endl;
                        break;
                    }
                }
                //key not found, insert now!
                maxval=0, temp=0;
                for(it= multi.begin(); it!=multi.end(); ++it){
                    if((x ^ *it) > maxval){
                        temp= *it;
                        maxval= (x ^ *it);
                    }
                }

                str a= {temp, maxval};
                check.insert(pair<int, str>(x, a));
                cout<<maxval<<endl;
                break;

        }
    }

    return 0;
}
