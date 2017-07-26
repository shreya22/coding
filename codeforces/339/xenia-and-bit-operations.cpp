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

int getMid(ll l, ll r){return l+(r-l)/2;}

unsigned ll updateFun(unsigned ll *st, ll ss, ll se, ll index, ll val, ll si, bool flag){

	if(index<ss || index>se) return st[si];

	// cout<<ss<<" "<<se<<" "<<index<<" "<<val<<" "<<si<<" "<<flag<<endl;

	if(ss==se) {
		st[ss]= val;
		return st[ss];
	}

	unsigned ll x, y;
	int mid= getMid(ss, se);
	x= updateFun(st, ss, mid, index, val, 2*si+1, !flag);
	y= updateFun(st, mid+1, se, index, val, 2*si+2, !flag);
	if(flag) st[si]= x | y;
	else st[si]= x ^ y;

	return st[si];
}

void update(ll *a, unsigned ll *st, int n, ll index, ll val){

	ll maxSize= pow(2, n);
	if(index<0 || index>maxSize-1) return;
	a[index]= val;

	bool flag; //flag=true => OR, flag=false => XOR
	if(n%2!=0) flag=true;
	else flag= false;

	updateFun(st, 0, maxSize-1, index, val, 0, flag);
}

unsigned ll makeSTFun(ll *a, unsigned ll *st, ll ss, ll se, ll si, bool flag){
	if(ss>se) return -1;
	if(ss==se){
		st[si]= a[ss];
		return st[si];
	}

	ll mid= getMid(ss, se);
	unsigned ll x, y;
	x= makeSTFun(a, st, ss, mid, 2*si+1, !flag);
	y= makeSTFun(a, st, mid+1, se, 2*si+2, !flag);

	if(flag) st[si]= x | y;
	else st[si]= x ^ y;
	return st[si];
}

unsigned ll *makeST(ll *a, ll n){
	bool flag; //flag=true => OR, flag=false => XOR
	if(n%2!=0) flag=true;
	else flag= false;

	ll maxSize= pow(2, n);
	ll treeSize= 2*maxSize-1;

	unsigned ll *st= new unsigned ll[treeSize];
	makeSTFun(a, st, 0, maxSize-1, 0, flag);

	// FOR(i, treeSize) cout<<st[i]<<" ";

	return st;
}

int main() {

	int n, m;
	cin>>n>>m;
	
	ll maxSize= pow(2, n);
	ll *a= new ll[maxSize];

	FOR(i, maxSize) cin>>a[i];
	unsigned ll *st= makeST(a, n);


	ll p, b;
	while(m--){
		cin>>p>>b;
		update(a, st, n, p-1, b);
		cout<<st[0]<<endl;
	}

    return 0;
}
