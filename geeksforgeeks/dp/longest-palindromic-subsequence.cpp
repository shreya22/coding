#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

//stl macros

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

int lpsFun(string str){
	int len= str.length();
	int lps[len][len];

	FOR(i, len)
		lps[i][i]= 1;

	FOR1(i, len){
		for(int j=i-1; j>=0; --j)
		{
			if(i == j+1 && str[i]==str[j]) lps[i][j] = 2;
			else if(str[i] == str[j]) lps[i][j]= 2 + lps[i-1][j+1];
			else lps[i][j]= max(lps[i-1][j], lps[i][j+1]); 
		}
	}

	return lps[len-1][0];
}

int lpsFun2(string str){
	int len= str.length();
	int lps[len][len];

	FOR(i, len)
		lps[i][i]= 1;

	FORrev(i, len){
		for(int j= i+1; j<len; ++j)
		{
			if(j == i+1 && str[i]== str[j]) lps[i][j] = 2;
			else if (str[i] != str[j]) lps[i][j]= max(lps[i+1][j], lps[i][j-1]);
			else lps[i][j]= lps[i+1][j-1] + 2;
		}
	}

	return lps[0][len-1];
}

int main() {

	string str;
	getline(cin, str);
	cout<<lpsFun2(str);

    return 0;
}
