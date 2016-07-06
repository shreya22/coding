#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	
	int n, m;
	cin>>n>>m;
	int f[m];
	for(int i=0; i<m; ++i) cin>>f[i];
	
	sort(f, f+m);
	long int diff=0, min=0;
	int x=0, y=n-1;
	
	while(y<m)
	{
		diff= f[y]- f[x];
		if(x==0) min= diff;
		else
			if(diff<min) min= diff;
		
		x++; y++;
	}
	
	cout<<min;
	
	return 0;
}
