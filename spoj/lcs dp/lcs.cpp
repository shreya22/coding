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
    //#define int a[10000];

//int arr[50001][50001];  
//string a, b;  
using namespace std;
int max(int a, int b){
	return (a>b)?a:b;
}

int lcs(int x, int y, char a[], char b[])
{
	if(x==0 || y==0){
		return 0;
	}
	
	if(a[x-1] == b[y-1]){
		return 1+ lcs(x-1, y-1, a, b);
	}
	else
	{	
		return max(lcs(x-1, y, a, b), lcs(x, y-1, a, b));
	}
	
	
}


int main()
{
	char a[50001], b[50001];
	char x;
	cin>>a>>x>>b;
	
/*	for(int i=0; i<a.length(); ++i)
	{
		for(int j=0; j<b.length(); ++j)
			arr[i][j]= -1;
	} */
	
	int ans= lcs(strlen(a), strlen(b), a, b);
	cout<<ans;
	
	
	return 0;
}
