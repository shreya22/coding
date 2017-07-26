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

int main() {

	int n;
	cin>>n;
	map<int, int> arr;
	map<int, int>::iterator i, j;

	int lengths[n];
	FOR(i, n) lengths[i]= 1;

	int temp1, temp2;
	FOR(i, n){
		cin>>temp1>>temp2;
		arr.insert(pair<int, int>(temp1, temp2));
	}

	int p=0, q=0;
	for(i= arr.begin(); i!=arr.end(); ++i){
		q=0;
		for(j= arr.begin(); j!= i; ++j){ 
			if(i->first > j->second && 1+lengths[q] > lengths[p]) lengths[p]= 1+lengths[q]; 
			q++;
		}
		p++;
	}

	int maxVal=-1;
	FOR(i, n) {
		maxVal= max(maxVal, lengths[i]);
	}
	cout<<maxVal;

    return 0;
}
