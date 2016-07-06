#include <iostream>
#include<algorithm>
using namespace std;

int num=-2;
int n; int k;

int min_per(int a[], int b[]){
	int a_per[n], b_per[n];
	
	a_per[-1]= 0; b_per[-1]= 0;
	
	for(int i=0; i<n; ++i){
		a_per[i]= min(a_per[i-1]+a[i], b_per[i-1]+b[i]+a[i]);
		b_per[i]= min(b_per[i-1]+b[i], a_per[i-1]+a[i]+b[i]);
		
	//	cout<<a_per[i]<<" "<<b_per[i]<<endl;
		
		if(a_per[i]>k && b_per[i]>k){
			num=i-1;//cout<<"******"<<num<<"*****"<<endl; break;
			//cout<<"num= "<<num<<endl; 
			break;
		}
	}
			if(num==-1) return 0;
		else if(num!=-2) return min(a_per[num], b_per[num]);
	else return min(a_per[n-1], b_per[n-1]);
}

int main() {
	// your code goes here
	
	cin>>n>>k;
	
	int a[n], b[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	for(int i=0; i<n; ++i) cin>>b[i];
	
	int ans= min_per(a, b);
	
	if(num==-1) cout<<"0 0";
	else if(num!=-2)cout<<num+1<<" "<<ans;
	else cout<<n<<" "<<ans;
	
	return 0;
}
