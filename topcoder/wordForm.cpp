#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <locale> //std::tolower
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)

int main() {

    string str; //string of input characters
    char flag; //temp character
    locale loc; //tolower function supporter

    cin>>str;
    FOR(i, str.length()) str[i]= tolower(str[i], loc);

    if(str[0]=='a' || str[0]=='e' || str[0]=='i' || str[0]=='o' || str[0]=='u'){
        cout<<"V";
        flag= 'v';
    }else{
        cout<<"C";
        flag= 'c';
    }

    FOR1(i, str.length()){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            if(flag == 'c'){
                cout<<"V";
                flag= 'v';
            }
        }
        else if(str[i] == 'y'){
            if(flag=='c'){
                cout<<"V";
                flag= 'v';
            }else{
                cout<<"C";
                flag= 'c';
            }
        }else{
            if(flag=='c');
            else{
                cout<<"C";
                flag='c';
            }
        }
    }

    return 0;
}
