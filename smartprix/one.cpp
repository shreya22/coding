#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define NULL 0

int main() {

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    string buffer;
    stringstream ss1(s1);
    stringstream ss2(s2);

    vector<string> sen1, sen2;
    while(ss1 >> buffer) sen1.pb(buffer);
    while(ss2 >> buffer) sen2.pb(buffer);

    int cnt=0;
    FOR(i, sen2.size())
    {

        if(sen2[i][0] == '%')
        {
            if(sen2[i][1] =='s')
            {
                if(sen2[i].size() >= 3)
                {
                    if(sen2[i][2] == ':')
                    {
                        // %s:_
                        // cout<<sen1[(int)sen2[i][3]-48];
                        // cout<<;

                        if(sen1[cnt].size() < (int)sen2[i][3]-48) cout<<sen1[cnt++];
                        else {
                            FOR(p, (int)sen2[i][3]-48) cout<<sen1[cnt][p];
                            cnt++;
                        }
                        for(int k=4; k<sen2[i].size(); ++k) cout<<sen2[i][k];
                            cout<<" ";
                    }else
                    {
                        //check for %s[_] or %s[_]: _
                        if(sen2[i].size() >= 4)
                        {
                            // %s[_]:_ && %s[_]
                            if(sen2[i][2]=='[' && sen2[i][4]==']')
                            {
                                if(sen2[i].size() >= 6)
                                {
                                    // %s[_]:_
                                    if(sen2[i][5]== ':')
                                    {
                                        // %s[_]:

                                        if(sen1[(int)sen2[i][3]-48].size() < (int)sen2[i][6]-48) cout<<sen1[(int)sen2[i][3]-48];
                                        else FOR(p, (int)sen2[i][6]-48) cout<<sen1[(int)sen2[i][3]-48][p];
                                        for(int k=7; k<sen2[i].size(); ++k) cout<<sen2[i][k]; cout<<" ";
                                    }else
                                    {
                                        cout<<sen1[(int)sen2[i][3]-48];
                                        for(int k=5; k<sen2[i].size(); ++k) cout<<sen2[i][k]; cout<<" ";
                                    }
                                }
                                else
                                {
                                    // %s[_]
                                    cout<<sen1[(int)sen2[i][3]-48];
                                    for(int k=5; k<sen2[i].size(); ++k) cout<<sen2[i][k]; cout<<" ";
                                }
                            }else
                            {
                                cout<<sen1[cnt++];
                                for(int k=2; k<sen2[i].size(); ++k) cout<<sen2[i][k]; cout<<" ";
                            }
                        }
                        else
                        {
                            cout<<sen1[cnt++];
                            for(int k=2; k<sen2[i].size(); ++k) cout<<sen2[i][k]; cout<<" ";
                        }
                    }
                }
                else{
                    //plain %s
                    cout<<sen1[cnt++]<<" ";
                }
            }
        }else
        {
            cout<<sen2[i]<<" ";
        }





    }

    return 0;
}
