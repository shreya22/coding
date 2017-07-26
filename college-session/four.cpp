#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

void array_of_pointers()
{
	// array of pointers
	int m, n;
	cin>>m>>n;

	int *a[m], *b[m], *c[m];
	FOR(i, m) a[i]= (int*)malloc(n*sizeof(int));
	FOR(i, m) b[i]= (int*)malloc(n*sizeof(int));
	FOR(i, m) c[i]= (int*)malloc(n*sizeof(int));

	cout<<"first matrix: ";
	FOR(i, m)
		FOR(j, n) 
			cin>>a[i][j];

	cout<<"second matrix: ";
	FOR(i, m)
		FOR(j, n) 
			cin>>b[i][j];

	FOR(i, m)
		FOR(j, n) 
		{
			c[i][j]= a[i][j] + b[i][j];
		}

	cout<<"array of pointers: sum matrix: \n";
	FOR(i, m)
	{
		FOR(j, n) 
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
}

void pointer_to_pointer()
{
	int m, n;
	cin>>m>>n;
	int **a, **b, **c;

	a= (int**)malloc(m*sizeof(int));
	b= (int**)malloc(m*sizeof(int));
	c= (int**)malloc(m*sizeof(int));

	FOR(i, m)
	{
		a[i]= (int*)malloc(n*sizeof(int));
		b[i]= (int*)malloc(n*sizeof(int));
		c[i]= (int*)malloc(n*sizeof(int));
	}

	FOR(i, m)
		FOR(j, n)
			cin>>a[i][j];

	FOR(i, m)
		FOR(j, n)
			cin>>b[i][j];

	FOR(i, m)
		FOR(j, n)
			c[i][j]= a[i][j] + b[i][j];

	cout<<"pointer of pointer: sum matrix: \n";
	FOR(i, m)
	{
		FOR(j, n) 
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
}

int main() {

	// array_of_pointers();
	pointer_to_pointer();

    return 0;
}
