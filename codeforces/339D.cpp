// http://codeforces.com/problemset/problem/339/D
// this question is of segment trees. i heck dont know what are they. right now, giving wrong answer
// on testcase 3. i'll come back to you

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define l long

struct node
{
    ll val;
    int parent;
};
vector<node> v[18];
int n, m;

void maketree()
{
    int flag=1; //flag=0 => OR, flag=0 => XOR

    FOR1(i, n+1)
    {
        node s;
        FOR(j, v[i-1].size())
        {
            if(flag)    s.val= v[i-1][j].val | v[i-1][j+1].val;   //bitwise OR
            else    s.val= v[i-1][j].val ^ v[i-1][j+1].val;   //bitwise XOR

            s.parent=-1;

            v[i-1][j].parent= v[i-1][j+1].parent= v[i].size();
            v[i].pb(s);

            j++;
        }
        flag++; flag%=2;
    }
}

int main() {
    cin>>n>>m;

    ll temp;
    node s;
    FOR(i, pow(2, n)){
        cin>>temp;

        s.val=temp;
        s.parent=-1;

        v[0].pb(s);
    }

    ll num, rep, x;
    int flag=0;   //flag=1 => XOR,  0=>OR
    FOR(i, m)
    {
        cin>>num>>rep;
        num-=1;

        if(i==0)
        {
            v[0][num].val= rep;
            maketree();
        }
        else
        {
            flag=0;
            FOR(i, n+1)     //while it is not the top node
            {
                v[i][num].val= rep; //FOR(p, v[i].size()) cout<<v[i][p].val<<" "; cout<<endl;
                if(i==n) break;

                if(num%2 == 0)
                    x= num+1;
                else
                    x= num-1;
// cout<<"index1 "<<v[i][num].val<<" index2: "<<v[i][x].val<<endl;
                if(flag == 1) rep= v[i][num].val ^ v[i][x].val;
                else rep= v[i][num].val | v[i][x].val;

                num= v[i][num].parent;
                flag++; flag%=2;

                // cout<<i<<": num "<<num<<" replacement "<<rep<<endl;
            }
        }
        // cout<<"blah"<<endl;
        cout<<v[n][0].val<<endl;

    }

    return 0;
}
