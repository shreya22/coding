#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)

int main() {

    map<int, int> values; //will store face values and corresponding scores
    int val;
    int result=0;
    int x;

    map<int, int>::iterator it;


    FOR(i, 6){
        x=i;
        values.insert(pair<int, int>(++x, 0));
    }

    FOR(i, 5){
        cin>>val;
        values.find(val)->second+= val;
    }

    for(it= values.begin(); it!=values.end(); ++it){
        result= max(result, it->second);
    }

    cout<<result;

    return 0;
}
