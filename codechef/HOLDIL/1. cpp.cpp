    #include <iostream>
    #include<cmath>
    #include<algorithm>
     
    using namespace std;
     
    int main() {
    	// your code goes here
     
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		long long s;
    		cin>>s;
     
    		long double x, y, z;
    		x= cbrt(3*s);
    		
    	//	cout<<x<<endl;
     
    		while(x*(x+1)*(2*x+1)/6 > s)
    		{
    	//		cout<<x*(x+1)*(2*x+1)/6<<endl;
    			x=ceil(x); x--;
    		}
    		cout<<(int)x<<endl;
    	}
     
     
    	return 0;
    }
