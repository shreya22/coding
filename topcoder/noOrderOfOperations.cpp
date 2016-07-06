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

    string str; //string of all numbers and operators
    int a; //first term
    int b; //second term
    char opr; //opeartor in between first and second terms

    cin>>str;
    a= (int)str[0]-48;

    FOR2(i, str.length()){
        opr= str[i];
        b= (int)str[i+1]-48;

        if(opr == '-') a-=b;
        else if(opr == '+') a+=b;
        else if(opr == '*') a*=b;
        else a/=b;
    }

    cout<<a;

    return 0;
}
