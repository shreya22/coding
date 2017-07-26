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

long hcf(long a, long b){
	if(b==0) return a;

	if(a<b) swap(a, b);
	return hcf(b, a%b);
}

long lcm(long a, long b){
	long x= a*b/hcf(a, b);
	return x;
}

int main() {

	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		long a, b, c;
		cin>>a>>b>>c;

        if(a==1 || b==1 || c==1) cout<<n<<endl;
        else{
            long ab, bc, ac, abc;
			ab= n/lcm(a, b);
    		bc= n/lcm(b, c);
    		ac= n/lcm(a, c);
    		abc= n/lcm(lcm(a, b), c);
    
    		long x, y, z;
    		x= n/a;
    		y= n/b;
    		z= n/c;
    
    		// cout<<x<<" "<<y<<" "<<z<<" "<<ab<<" "<<bc<<" "<<ac<<" "<<abc<<" "<<endl;
    
    		// long ans= x+y+z-ab-bc-ac-2*abc;
    		// cout<<ans<<endl;
    		if(a==b && b!=c){
    			cout<<y+z-bc<<endl;
    		}else if(b==c && c!=a){
    			cout<<x+z-ac<<endl;
    		}else if(a==c && a!=b){
    			cout<<x+y-ab<<endl;
    		}else if(a==b && b==c){
    			cout<<x<<endl;
    		}else{
    			long ans= x+y+z-ab-bc-ac-2*abc;
    			cout<<ans<<endl;
    		}
        }
	}

    return 0;
}
