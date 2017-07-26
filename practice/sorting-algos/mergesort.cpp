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

void merge(int *a, int s, int m, int e){
	int n1= m-s+1;
	int n2= e-m;
	int a1[n1], a2[n2];

	FOR(i, n1) a1[i]= a[s+i];
	FOR(i, n2) a2[i]= a[m+i+1];

	int i=0, j=0, cnt=0;
	while(i<n1 && j<n2){
		if(a1[i]<=a2[j]){
			a[s++]= a1[i];
			i++;
		}else{
			a[s++]= a2[j];
			j++;
		}
	}
	while(i<n1) a[s++]= a1[i++];
	while(j<n2) a[s++]= a2[j++];
}

void mergesort(int *a, int start, int end){
	if(end > start){
		int mid= (end+start-1)/2;
		mergesort(a, start, mid);
		mergesort(a, mid+1, end);
		merge(a, start, mid, end);
	}
}

int main() {

	int n;
	cin>>n;
	int a[n];
	FOR(i, n) cin>>a[i];

	mergesort(a, 0, n-1);
	FOR(i, n) cout<<a[i]<<" ";

    return 0;
}
