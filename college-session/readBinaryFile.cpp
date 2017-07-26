#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	FILE *fp;
	fp= fopen("a.abc", "rb");
	
	if(fp==NULL){
		cout<<"could not open file!";
		return 0;
	}

	int x;
	int t=9;
	while(!feof(fp))
	{
		fread(&x, sizeof(int), 1, fp);
		cout<<x<<endl;
	}

	// fseek(fp, +sizeof(int), SEEK_)

	fclose(fp);

	return 0;
}