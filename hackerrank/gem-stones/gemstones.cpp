#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

vector <string> v;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	string str;
	for(int i=0; i<n; ++i)
	{
		cin>>str;
		v.push_back(str);
	}
	
	int temp= 0;
	
	int a[26] = {0};
	int chk[26]= {false};
	
	for(int i=0; i<v[0].length(); ++i)
	{
		if(chk[(int)v[0][i] - 97] == true) continue;
		
		for(int j=1; j<n; ++j)
		{
			if(v[j].find(v[0][i]) == -1)
			{
				temp= 1;
				break;
			}
				
		}
		if(temp == 0)
			a[(int)v[0][i] - 97]= 1;
			
		temp= 0;
	}
	
	int count=0;
	for(int i=0; i<26; ++i)
		if(a[i] == 1) count++;
	
	cout<<count;
	
	return 0;
}
