#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)

int main() {

    string people[51];
    int ppl[51][51];
    string row;
    int len; //num or rows in array
    char * temp; //temp char
    int tmp1, tmp2; //temp int

    cin>>len;
    //cin>>x; //to fit in place

    FOR(i, len+1) getline(cin, people[i]);
    FOR1(i, len+1)
    {
        tmp1=i; tmp2=0;

        temp= strtok(people[i], " ");
        while(temp!=NULL){
            ppl[tmp1-1][tmp2]= (int)temp[0] - 48;
            tmp2++;
        }
    }

    FOR(i, len)
    {
        FOR(j, tmp2)
            cout<<ppl[i][j]<<" ";
            cout<<endl;
    }



    return 0;
}

