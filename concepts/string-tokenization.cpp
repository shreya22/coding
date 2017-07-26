// istringstream takes input as an string, breaks it with the delimiters provided,
// and then points to the first value broken. As we dump it in a var/string, it incrementally points 
// to the next in the series. 


#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	string s;
	getline(cin, s);
	vector<string> v;

	istringstream iss(s);
	string val;
	while(1){
		iss>>val; 

		if(iss == NULL) break;
		v.push_back(val);
	}

	for(int i=0; i<v.size(); ++i){
		cout<<v[i]<<endl;
	}

	istringstream iss(s);
	string token;
	while(getline(iss, token, ',')){
		cout<<token<<" ";
	}

	return 0;
}