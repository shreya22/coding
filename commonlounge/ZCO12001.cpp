 // Given a well-bracketed sequence, we are interested in computing the following:
 // The nesting depth, and the first position where it occurs–this will be the position of the first opening bracket at this nesting depth, where the positions are numbered starting with 1.
 // The maximum number of symbols between any pair of matched brackets, including both the outer brackets, and the first position where this occurs–that is, the position of the first opening bracket of this segment

// approach goes as:
// depthstack- counter to count no of opening brackets which have not been closed yet
// diffStaxk- stack to store index of opening brackets which are next to be popped, popped on
//         getting a closing bracket and value of index popped is stored in diffArray


#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int main() {

    int n;
    cin>>n;

    int depthStack=0, maxDepth=0, maxDiff=0, maxDepthPos=-1, maxDiffPos=-1;
    int array[n+1], diffArray[n+1];
    stack<int> diffStack;

    int temp;
    FOR1(i, n+1) {
        cin>>temp;
        array[i]= temp;

        if(temp == 1) {
            diffStack.push(i);
            diffArray[i]= -1;

            depthStack++;
        }
        else{
            diffArray[i]= diffStack.top();
            diffStack.pop();

            maxDepth= (depthStack>maxDepth)?depthStack:maxDepth;
            depthStack--;

            maxDiff= (i-diffArray[i]+1 > maxDiff)?(i-diffArray[i]+1):maxDiff;
        }

    }
    // FOR1(i, n+1) cout<<diffArray[i]<<" ";

    int tempMaxDepth=0;
    FOR1(i, n+1)
    {
        if(array[i]==1) tempMaxDepth++;
        else {
            if(tempMaxDepth== maxDepth){
                maxDepthPos= i-1;
                break;
            }
            tempMaxDepth--;
        }
    }

    FOR1(i, n+1){
        if(array[i]==2)
            if(i-diffArray[i]+1 == maxDiff){
                maxDiffPos= i;
                break;
            }
    }

    maxDiffPos= maxDiffPos-maxDiff+1;
    cout<<maxDepth<<" "<<maxDepthPos<<" "<<maxDiff<<" "<<maxDiffPos;


    return 0;
}
