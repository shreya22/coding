#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	FILE *fp;
	fp= fopen("b.abc", "wt");
	
	if(fp==NULL){
		cout<<"could not open file!";
		return 0;
	}

	for(long i=100000; i<100009; ++i){
		fprintf(fp, "%ld ", i);
	}

	fclose(fp);

	return 0;
}