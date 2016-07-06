//learnt using custom sort
//using struct as a datatype
//vector of structs

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <cctype> //toupper, tolower
#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)

struct country{
    string name;
    int g=0; int s=0; int b=0;
};                      //contains country details

vector<country> c;

void add(string name, int g, int s, int b){
    //if the name already exists in vector, add remaining
    //else, add the name also, push_back vector

    FOR(i, c.size()){
        if(c[i].name == name){
            c[i].g+=g;
            c[i].s+=s;
            c[i].b+=b;
            return;
        }
    }
    //name doesnt exist already, so add it!
    country temp = {name, g, s, b};
    c.push_back(temp);
}

bool customsort(country i, country j){
    if(i.g != j.g) return i.g>j.g;
    if(i.s != j.s) return i.s>j.s;
    if(i.b != j.b) return i.b>j.b;
    return i.name < j.name;
}

int main() {

    string g, s, b; //g: country who won gold, and so on

    int n; //num of matches total
    cin>>n;

    while(n--){
        cin>>g>>s>>b;
        add(g, 1, 0, 0);    // g+1 to country who won gold
        add(s, 0, 1, 0);    // s+1 to country who won silver
        add(b, 0, 0, 1);    // b+1 to country who won bronze
    }

    sort(c.begin(), c.end(), customsort);

    FOR(i, c.size())
        cout<<c[i].name<<" "<<c[i].g<<" "<<c[i].s<<" "<<c[i].b<<endl;

    return 0;
}
