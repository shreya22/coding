#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)

int main() {
    int n; //num of women/men
    int len; //num of ans

    map<string, string> women;
    map<string, string> men;
    map<int, string> menlen;

    map<string, string>::iterator iter_w, iter_m, iter_s;
    map<int, string>::iterator iter_i;
    map<int, string>::reverse_iterator iter_rev;

    string name, ans;
    string splname;
    int cnt;
    string ansname; //nam of boy
    string currwoman;

    cout<<"num of women: ";
    cin>>n;

    cout<<"name and an of women: ";
    FOR(i, n){
        cin>>name>>ans;
        women.insert(pair<string, string>(name, ans));
    }

    cout<<"name and an of men: ";
    FOR(i, n){
        cin>>name>>ans;
        men.insert(pair<string, string>(name, ans));
    }

    cout<<"name of special woman: ";
    cin>>splname;

    iter_w= women.begin();
    do{
       //for all women before and including our one, iterate through each man

        for(iter_m= men.begin(); iter_m!= men.end(); ++iter_m){
            //for each man, calculate match count with corr woman

            cnt=0;
            FOR(i, iter_w->second.length())
                if(iter_w->second[i] == iter_m->second[i])
                    cnt++;

            //insert data for each man in map menlen
            menlen.insert(pair<int, string>(cnt, iter_m->first));
        }

        //reverse iterate, find name of man which is lexicographically smallest btwn all with max cnt
        iter_rev= menlen.rbegin();
        while(iter_rev->first == menlen.rbegin()->first){
            //run this while we loop through all menlen with max cnt

            ansname= iter_rev->second;
            iter_rev++;
        }

        cout<<iter_w->first<<" "<<ansname<<endl;

        currwoman= iter_w->first; cout<<"current: "<<currwoman<<endl;

        //delete them from lists
        women.erase(iter_w);
        menlen.clear();
        men.erase(ansname);
        iter_w= women.begin();

    }while(currwoman != splname);

    return 0;
}
