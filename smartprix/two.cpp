#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

vector<string> sen1, sen2;
int cnt=0, x, temp=0;

void fun(int i, int j)
{
    if(sen2[i][j]== '%')
    {
        if(sen2[i][j+1] == 's')
        {
            if(sen2[i][j+2] == ':')
            {
                if(sen2[i].size()>=3)
                {
                    if(isdigit(sen2[i][j+3]))
                    {
                        if(sen1[cnt].size() < (int)sen2[i][j+3]-48) cout<<sen1[cnt++];
                        else{
                            FOR(p, (int)sen2[i][j+3]) cout<<sen1[cnt][p];
                            cnt++;
                        }

                        x=1;
                        temp= 3;
                        return;
                    }else
                    {
                        //not a digit, do nothing
                        x=0;
                        temp=0;
                        return;
                    }
                }
                //else do nothing
            }
            else if(sen2[i][j+2] == '[' && isdigit(sen2[i][j+3]) && sen2[i][j+4] == ']')
            {
                //no colon
                // check for %s[_] or %s[_]:_

                if(sen2[i][j+5] == ':' && isdigit(sen2[i][j+6]))
                {
                    // %s[_]:_
                    if(sen1[(int)sen2[i][j+3]-48].length() <= (int)sen2[i][j+6] -48) cout<<sen1[(int)sen2[i][j+3]-48];
                    else
                        FOR(p, (int)sen2[i][j+6]-48) cout<<sen1[(int)sen2[i][j+3]-48][p];

                    x=1;
                    temp= 6;
                    return;

                }
                else
                {
                    // %s[_]
                    cout<<sen1[(int)sen2[i][j+3]-48];

                    x=1;
                    temp= 4;
                    return;
                }
            }
            else
            {
                //plain %s
                cout<<sen1[cnt++];
                x= temp= 1;
                return;

                if(sen2[i][j+2] && )
            }
        }
    }

    x=0; temp=0;
    return;
}

int main() {

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    string buffer;
    stringstream ss1(s1);
    stringstream ss2(s2);

    while(ss1 >> buffer) sen1.pb(buffer);
    while(ss2 >> buffer) sen2.pb(buffer);

    FOR(i, sen2.size())
    {
        FOR(j, sen2[i].size())
        {
            fun(i, j);

            if(!x) cout<<sen2[i][j];
            else
            {
                j+= temp;
            }
        }
        cout<<" ";
    }

    return 0;
}
