#include <iostream>
using namespace std;

int max(int a, int b)
{
	return (a>b)?a:b;
}

int lcs(int x, int y, int a[], int b[])
{
	//anshul i love you bht zyada
	if(x==0 || y==0) return 0;
	 
	if(a[x-1] == b[y-1]) return 1+ lcs(x-1, y-1, a, b);
	
	return max(lcs(x-1, y, a, b), lcs(x, y-1, a, b)); 
}

int main() {
	// your code goes here
	
	int d;
	cin>>d;
	int cnt=0, girl[2001]= {-1}, boy[2001]= {-1};
	int max=0, tmp1=-1, tmp2=-1, ans=0, i=0, j=0, tmp3=-1;
	while(cnt<d)
	{
		ans=0;max=0;
		for(j=0; ; ++j)
		{
			cin>>tmp3;
			if(tmp3==0) break;
			else girl[j]= tmp3;
		}
		
	//	for(int p=0; p<j; ++p) cout<<girl[p]<<" ";
	//	cout<<endl;
		
		cin>>tmp1;
		while(tmp1!= 0)
		{
			boy[0]=tmp1;
			for(i=1; ; ++i)
			{
				cin>>tmp2;
				if(tmp2==0) break;
				else boy[i]= tmp2;
			}
			
	//		for(int p=0; p<i; ++p) cout<<boy[p]<<" ";
	//	cout<<endl;
		//	cout<<j<<"girl "<<i<<"boy \n";
			ans= lcs(j, i, girl, boy);
			if(max<ans) max= ans;
			
			cin>>tmp1;
		}
		cout<<max<<endl;
		
		for(int p=0; p<i; ++p)
			boy[p]= -1;
		for(int p=0; p<j; ++p)
			girl[p]= -1;
		
		
		cnt++;
	}
	
	return 0;
}
