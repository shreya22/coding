#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		
		long int arr[a]; long long sum=0, temp=0, dist=0, disf=0,c=0, x=0, y=0;
		
		for(int i=0; i<a; ++i){
			cin>>arr[i];
			temp+=arr[i]; y++; dist++;
			
	//	if(c==0){
	//			if(arr[i]>b) c=1;
				
				if(temp>b){
					while(x<y && temp>b){
						temp= temp-arr[x];
						x++;
						dist--;
					}
				}
				
				if(dist > disf){
					disf= dist;
					sum= temp;
				}
				
				if(dist == disf){
					sum= (sum<temp)?sum:temp;
				}
				
				
	//		}
			
			
		}
		
		cout<<sum<<endl;
		
	}
	
	
	return 0;
}
