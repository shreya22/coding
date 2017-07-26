// given postfix notation, evaluate
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

void push(int stack[], int *top, char x){
	*top++;
	stack[*top]= x;
}

int pop(int stack[], int *top)
{
	*top--;
	return (int)stack[top];
}

int main() {

	string s;
	getline(cin, s);

	int stack[s.length()], top=0;
	FOR(i, s.length())
	{
		if(s[i]>'0' && s[i]<'9') push(stack, &top, (int)s[i]);
		else{
			int a= pop(stack, &top);
			int b= pop(stack, &top);
			int c;

			switch(s[i]){
				case '+':
					c= a+b;
				case '-':
					c= a-b;
				case '*':
					c= a*b;
				case '/':
					c= a/b;
				default:
					c=0;
			}

			push(stack, &top, c);
		}
	}

    return 0;
}
