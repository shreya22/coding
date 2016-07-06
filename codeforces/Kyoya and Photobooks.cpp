#include <iostream>
#include<cstring>
using namespace std;

int main() {
	// your code goes here
	
	string str;
	cin>>str;
	int x= (str.length()+1)*(26 - 1) + 1;
	
	cout<<x;
	
	return 0;
}
