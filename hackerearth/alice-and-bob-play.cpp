/* 
Alice and Bob are playing a game yet again. There is a grid with 
N rows and M columns. Each cell of this grid is initially empty.
Alice and Bob play turn wise, with Alice playing first. In each turn, the player whose turn it is can choose a cell and write a non-negative 32-bit unsigned integer in it. After all the cells are filled, 
N values are computed, such that the ith of them denotes the xor of all the values in the 
ith row. If any of the 
N values computed is 0, then Alice loses and Bob wins. Otherwise, Alice wins. For better understanding, refer to sample explanation.
You will be given the integers 
N and 
M. Find out who will win the game.
You can assume that since Alice and Bob have been playing a lot of games since the beginning of time, they will be playing optimally.
*/


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
		ll n, m;
		cin>>n>>m;

		if(m==1 && n>1) cout<<"Bob\n";
		else if(n%2==0 || m%2==0) cout<<"Bob\n";
		else cout<<"Alice\n";
	}

    return 0;
}
