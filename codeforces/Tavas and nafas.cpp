#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	char *unit[10]= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char *one[10]={"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *part1[10]= {"crap  ", "crap  ", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	
	int n;
	cin>>n;
	
	int a, b;
	b= n%10;
	a= n/10;
	
	if(a==0)cout<<unit[b];
	else{
		if(a==1) cout<<one[b];
		else {
			if(b!=0) cout<<part1[a]<<"-"<<unit[b];
			else cout<<part1[a];
		}
	}
	
	
	return 0;
}
