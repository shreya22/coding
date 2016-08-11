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
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)

stack<int> makequeue(stack<int> s, int n)
{
    int temp;
    FOR(i, n){
        cin>>temp;
        s.push(temp);
    }
    return s;
}

int makeequal(stack<int> s1, stack<int> s2, stack<int> s3)
{
    int sum1= getsum(s1);
    int sum2= getsum(s2);
    int sum3= getsum(s3);
    int max=0;

    if(sum1 == sum2 == sum3) return sum1;
    while(sum1 && sum2 && sum3){
        max= (sum1 > (sum2>sum3?sum2:sum3)?sum1:(sum2>sum3?sum2:sum3));

        if(max == sum1) s1.pop();
        else if(max == sum2) s2.pop();
        else if(max == sum3) s3.pop();
        else;

        cout<<max<<" ";

        makeequal(s1, s2, s3);
    }
    return 0;
}

int main() {

    int n1, n2, n3;
    cin>>n1>>n2>>n3;

    queue<int> s1, s2, s3;

    s1= makequeue(s1, n1);
    s2= makequeue(s2, n2);
    s3= makequeue(s3, n3);

    int ans;
    ans= makeequal(s1, s2, s3);
    cout<<ans;

    return 0;
}
