#include <iostream>
#include <algorithm>
#include <cmath>
#include<cstring>
#include<sstream>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)

int main() {
    // your code goes here

    string a[51], exist;

    int n=0;
    while(cin>>exist){
        a[n]= exist;
        n++;
    }

    cout<<"enter newName";

    string newName;
    cin>>newName;

    cout<<"input is: "<<newName<<endl;

    int flag=0;

    sort(a, a+n);
    FOR(i, n){
        if(a[i] == newName){

            flag=1;

            //match found, look in consequtive terms for names with appended indice
            int cnt=0;
            while(++i < n){
                if(!(a[i] == newName + to_string(cnt++))){
                    cout<<newName + to_string(i);
                    break;
                }
                //cnt++;
            }
            break;

        }
    }
    cout<<flag;
    if(!flag)
        cout<<newName;

    return 0;
}
