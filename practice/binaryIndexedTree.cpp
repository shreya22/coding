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

int n;

int prefixSum(int *a, int x){
	int index= x;
	int sum=0;
	while(index){
		sum+= a[index];
		index-= index & -index;
	}
	return sum;
}

void sum(int *a, int x, int y){
	cout<<"sum is "<<prefixSum(a, y) - prefixSum(a, x-1);
}

void update(int *a, int x, int y){
	int index= x;
	while(index <=n){
		a[index]+= y;
		index+= index & -index;
	}
}

int* createBIT(vector<int> a){
	int *b;
	b[0]= 0;
	FOR1(i, n+1) b[i]= 0;
	FOR1(i, n+1){
		update(b, i, a[i]);
	}
	cout<<"tree created\n";
	return b;
}

int main() {

	cout<<"enter no of array elements:\n";
	cin>>n;

	cout<<"enter array elements: \n";
	vector<int> a;
	a.pb(-1);

	int temp;
	FOR1(i, n+1) {
		cin>>temp;
		a.pb(temp);
	}

	int *b= createBIT(a);

	FOR1(i, n+1) cout<<b[i]<<" ";
	cout<<endl;

	cout<<"1-modify x to y, 2-SUM from x to y\n";
	cout<<"enter no of operations\n";
	int m;
	cin>>m;

	int flag; int x, y;
	while(m--){
		cin>>flag>>x>>y;
		if(flag==1) update(b, x, y);
		else sum(b, x, y);
	}

    return 0;
}
