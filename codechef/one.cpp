#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int min(int a, int b, int c)
{
	return (a<(b<c?b:c)?a:(b<c?b:c));	
}

int main() {
	// your code goes here
	
	int n, a, b, c, d, e, f, g;
	cin>>n>>a>>b>>c>>d>>e>>f>>g;
	int ans;
	
	ans= min(a*b/f, c*d, e/g);
	ans= ans/n;
	
	cout<<ans<<endl;
	
	return 0;
}
