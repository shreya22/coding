#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR2(i, n) for(int i=1; i<n; i+=2)

int main() {

    int n; //num of subjects
    int pointsEarned[21]; //points earned by us
    int pointsPossibel[21]; //possible max points
    int finalExam; //max points of final exam
    int finalReq; //points required in final exam to pass

    float sumtotal=0; //total marks reqd in curriculam
    int mysum=0; //my total marks

    cin>>n;
    FOR(i, n){
        cin>>pointsEarned[i];
        mysum+= pointsEarned[i];
    }

    FOR(i, n){
        cin>>pointsPossibel[i];
        sumtotal+= pointsPossibel[i];
    }

    cin>>finalExam;
    sumtotal+= finalExam;

    finalReq= ceil((sumtotal*65)/100);
    if(mysum >= finalReq) cout<<"0";
    else if( (finalReq-mysum) > finalExam)cout<<"-1";
    else cout<<(finalReq - mysum);


    return 0;
}
