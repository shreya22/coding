#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    int n, h;
    cin>>n>>h;

    int a[n];
    FOR(i, n) cin>>a[i];

    int step, current=0; //current- current position of the box
    bool isHolding= false; //current;y not holding any box

    cin>>step;
    while(step)
    {
        switch(step){
            case 1:
                if(current != 0) current--;
                break;

            case 2:
                if(current!=n-1) current++;
                break;

            case 3:
                if(isHolding == false && a[current]>0) {
                    isHolding= true;
                    --a[current];
                };
                break;

            case 4:
                if(isHolding == true && a[current]<h) {
                    isHolding= false;
                    ++a[current];
                };
                break;

            case 0:
                break;
        }

        cin>>step;
    }

    FOR(i, n) cout<<a[i]<<" ";

    return 0;
}
