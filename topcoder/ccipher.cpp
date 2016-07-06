#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR2(i, n) for(int i=1; i<n; i+=2)

int main() {

    string str; //cipher string
    int cnt; //val to be reduced from each int
    char val;

    cin>>str;
    cin>>cnt;

    FOR(i, str.length()){

        val= int(str[i]) - cnt;
        if( val<65 ) val= 91-( 65- val );

        str[i]= char(val);
    }
    cout<<str;

    return 0;
}
