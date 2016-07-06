#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	 int t;
	 cin>>t;
	 while(t--){
	 	string a, b;
	 	cin>>a>>b;
	 	int l1, l2, flag=0;
	 	
	 	l1= a.length(); l2= b.length();
	 	int c=0, i, cnt=0, x=0;
	 	
	 	for(i=0; i<l2; ++i){
	 		
	 		if(b[i]==a[c]) cout<<"yippee";
	 		else{
	 			if(c!= (l1-1)){
	 				if(a[c+1]==b[i]){
	 					cnt++;
	 					c++; cout<<"c= "<<c+1<<"i= "<<i<<endl;
	 				}
	 				else{
	 					cnt++; cout<<"c= "<<c<<"i= "<<i<<endl;
	 				}
	 			}else{
	 				cnt++; cout<<"c= "<<c<<"i= "<<i<<endl;
	 				flag=1;c++; i++;
	 				break;
	 			}
	 		}
	 		c++;
	 	}
	 //	cout<<"c= "<<c<<" i= "<<i<<endl;
	 	if(flag==0){
	 		 x= l1-c;
	 		 cout<<"l1= "<<l1<<" c "<<c<<endl;
	 	}
	 	else{
	 		x= l2-i;
	 		 cout<<"l2= "<<l2<<" i "<<i<<endl;
	 	}
	 	cnt+=x; cout<<endl<<x<<endl;
	 	cout<<cnt<<endl;
	 }
	
	
	
	return 0;
}
