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

struct Box
{
	int h, w, d;
};

int compare(const void *a, const void *b){
	return ( (*(Box*)b).w * (*(Box*)b).d ) - ( (*(Box*)a).w * (*(Box*)a).d );
}

int stackBoxes(Box arr[], int n){
	Box row[3*n];
	int index=0;
	FOR(i, n){
		row[index]= arr[i];

		index++;

		// 2nd rotation
		row[index].h= arr[i].w;
		row[index].w= max(arr[i].h, arr[i].d);
		row[index].d= min(arr[i].h, arr[i].d);

		index++;
		// 3nd rotation
		row[index].h= arr[i].d;
		row[index].w= max(arr[i].h, arr[i].w);
		row[index].d= min(arr[i].h, arr[i].w);
	}

	n= n*3;
	int maxHeight[n];
	FOR(i, n) maxHeight[i]= row[i].h;

	qsort(row, n, sizeof(row[0]), compare);

	FOR1(i, n){
		for(int j=0; j<i; ++j)
		{
			if(row[j].h + maxHeight[j] > maxHeight[i] && row[j].w > row[i].w && row[j].d > row[i].d) maxHeight[i]= row[j].h + maxHeight[j];
		}
	}

	cout<<maxHeight[n-1];
}

int main() {

	int n;
	cin>>n;
	Box arr[n];

	int x, y, z;
	FOR(i, n){
		cin>>x>>y>>z;
		arr[i].h= x;
		arr[i].w= y;
		arr[i].d= z;
	}

	cout<<stackBoxes(arr, n);


    return 0;
}
