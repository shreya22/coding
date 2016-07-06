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
    #include<cmath>
  
  int max(int a, int b)
  {
  	return (a>b)?a:b;
  }
  
  using namespace std;
  int main()
  {
  	char a[5001], b[5001];
  	int lcs[501][501];
  	
  	cin>>a>>b;
  	
  	int m= strlen(a), n=strlen(b);
  	for(int i=0; i<=m; ++i)
  	{
  		for(int j=0; j<=n; ++j)
  		{
  			if(i==0 || j==0) lcs[i][j]=0;
  			
  			else if(a[i-1] == b[j-1])
  				lcs[i][j] = 1+ lcs[i-1][j-1];
  			
  			else
  				lcs[i][j]= max(lcs[i-1][j], lcs[i][j-1]);
  		}
  	}
  	
  	cout<<lcs[m][n];
  	
  	
  	return 0;
  }
