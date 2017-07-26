#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	FILE *fp;
	fp= fopen("b.txt", "rt");
	
	if(fp==NULL){
		cout<<"could not open file!";
		return 0;
	}

	int x;
	while(!feof(fp)){
		fscanf(fp, "%d ", &x);
		cout<<x<<" ";
	}

	fclose(fp);

	return 0;
}