#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int n;
set<int> a;
set<int>::reverse_iterator rit;
int maxval=-1;
int primes[]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};


void makeset()
{
    int temp;
    FOR(i, n){
        cin>>temp;
        a.insert(temp);
    }
    return;
}

void getmax()
{
    int temp, prime;
    for(rit= a.rbegin(); rit!= a.rend(); ++rit){

        if(*rit ==1) continue;

        prime=1;
        FOR(j, 11)
        {
            if(*rit%primes[j] == 0 && *rit!=primes[j]){
                prime= 0; break;
            }
        }
        if(prime) {
            maxval= *rit;
            break;
        }
    }
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        makeset();

        getmax();
        if(maxval == -1) cout<<maxval<<endl;
        else cout<<pow(maxval, 2)<<endl;

        // cout<<a.size()<<" ";
        a.clear();
        maxval= -1;
        // cout<<a.size()<<endl;
    }

    return 0;
}
