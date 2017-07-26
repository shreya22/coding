#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	FILE *fp;
	fp= fopen("a.abc", "wb");
	
	if(fp==NULL){
		cout<<"could not open file!";
		return 0;
	}

	for(int i=100000; i<100009; ++i){
		fwrite(&i, sizeof(int), 1, fp);
	}

	fclose(fp);

	return 0;
}