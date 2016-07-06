     #include <set>
    #include <map>
    #include <list>
    #include <cmath>
    #include <ctime>
    #include <deque>
    #include <queue>
    #include <stack>
    #include <cctype>
    #include <cstdio>
    #include <string>
    #include <vector>
    #include <cassert>
    #include <cstdlib>
    #include <cstring>
    #include <sstream>
    #include <iostream>
    #include <algorithm>
    #include<cstdio>
    //#define int a[10000];
    using namespace std;
    int main()
    {
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[n]; long int sum=0, cnt=0;
    for(int i=0; i<n; ++i)	
    {
    cin>>a[i];
    sum+= a[i];
    if(a[i]==0) cnt++;
    }
    // cout<<sum<<endl;
    if(sum<100)
    cout<<"NO\n";
    else if(sum==100) cout<<"YES\n";
    else
    {
    sum= sum-100;
    if(sum < n-n/10-cnt)
    cout<<"YES\n";
    else
    cout<<"NO\n";
    }
    }	
    return 0;
    } 
