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

int getMid(int l, int r){return l+(r-l)/2;}

int getSumFun(int *st, int ss, int se, int qs, int qe, int si){
	// if node completely in range
	if(qs<=ss && qe >=se) return st[si];
	else if(qs>se || qe<ss) return 0;

	int mid= getMid(ss, se);
	return getSumFun(st, ss, mid, qs, qe, 2*si+1) + getSumFun(st, mid+1, se, qs, qe, 2*si+2);
}

int getSum(int *st, int n, int l, int r){
	if(l>r) return -1;
	if(l<0 || r>n-1) return -1;
	return getSumFun(st, 0, n-1, l, r, 0);
}

void updateFun(int *st, int ss, int se, int index, int diff, int si){ 
	if(index<ss || index>se) return;
	st[si]= st[si]+diff;

	if(ss!=se){
		int mid= getMid(ss, se);
		updateFun(st, ss, mid, index, diff, 2*si+1);
		updateFun(st, mid+1, se, index, diff, 2*si+2);
	}
}

int update(int *a, int *st, int n, int index, int val){
	if(index<0 || index >n-1) return -1;

	int diff= val - a[index];
	a[index]= val;
	updateFun(st, 0, n-1, index, diff, 0);
}

int constructSTFun(int *a, int ss, int se, int *st, int si){
	if(ss>se) return -1;
	if(se == ss){
		st[si]= a[ss];
		return st[si];
	}

	int mid= getMid(ss, se);
	st[si]= constructSTFun(a, ss, mid, st, 2*si+1) +constructSTFun(a, mid+1, se, st, 2*si+2);
	return st[si];
}

int *constructST(int *a, int n){
	int height= (int)ceil(log2(n));
	int maxNodes= pow(2, height+1)-1;
	int *st= new int[maxNodes];
	constructSTFun(a, 0, n-1, st, 0);

	return st;
}

int main() {

	int n;
	cin>>n;

	int *a;
	FOR(i, n) cin>>a[i];

	int *st= constructST(a, n);
	int q;
	cin>>q;

	int flag, x, y;
	while(q--){
		cin>>flag>>x>>y;
		if(flag==0) update(a, st, n, x, y);
		else cout<<getSum(st, n, x, y);
	}

    return 0;
}
