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
#include <stack>
#include <queue>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n, id;
        int poss1;  //will store id of the player having ball before current
        int poss2;  //will store id of player currently having the ball

        cin>>n>>id;
        char str;

        poss1= id;
        poss2= id;

        FOR(i, n)
        {
            cin>>str;
            if(str == 'P'){
                //have to pass the ball to player with id 'id'
                //poss 1 will contain old id, and poss2 will store new input id

                poss1= poss2;
                cin>>poss2;
            }else{
                //pass back the ball to previous player
                //poss1 and poss2 will interchange values

                swap(poss1, poss2);
            }
        }

        cout<<"Player "<<poss2<<endl;
    }

    return 0;
}
