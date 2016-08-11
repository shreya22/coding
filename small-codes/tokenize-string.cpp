#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str("shreya sahu it is!");
    string buf; // Have a buffer string
    stringstream ss(str); // Insert the string into a stream

    vector<string> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);

    for(int i=0; i<tokens.size(); ++i)cout<<tokens[i]<<endl;
}
