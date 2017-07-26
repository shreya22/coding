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

	int t;
	cin>>t;
	while(t--){
		string s, t;
		cin>>s>>t;

		int a[26], b[26];
		FOR(i, 26){
			a[i]= 0;
			b[i]= 0;
		}

		int count=0;
		bool flag= false;

		FOR(i, s.length()){
			a[int(s[i])-97]++;
		}
		FOR(i, t.length()){
			b[int(t[i])-97]++;
		}

		FOR(i, 26){
			if(b[i] < a[i]){
				flag= true;
				break;
			}
			b[i]-= a[i];
			if(b[i]) count++;
		}
		if(flag) cout<<"-1\n";
		else cout<<count<<endl;
	}

    return 0;
}
