#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isOperator(char c)
{
	if(c=='+'||c=='*'||c=='-'||c=='/')
		return true;
	else
		return false;
}
bool isOperand(char c)
{
	if(c >= '0' && c <= '9') return true;
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	return false;
}
int GetOperatorWeight(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '$':
			return 3;
	}
}
bool HasHigherPrecedence(char c,char d)
{
	int c_weight=GetOperatorWeight(c);
	int d_weight=GetOperatorWeight(d);
	if(c_weight==d_weight)
	{
		if(c=='$')
			return false;
		else
			return true;
	}
	return c_weight>d_weight ? true:false;
}
void infix_to_postfix(string c,int len)
{
	stack<char> s;
	string postfix="";
	for(int i=0;i<len;i++)
	{
		if(c[i]==' '||c[i]==',')
			continue;
		else if(isOperand(c[i]))
			postfix=postfix+c[i];
		else if(c[i]=='(')
			s.push(c[i]);
		else if(c[i]==')')
		{
			while(!s.empty()&&s.top()!='('){
				postfix+=s.top();
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(c[i]))
		{
			while(!s.empty()&&s.top()!='('&&HasHigherPrecedence(s.top(),c[i])){
			postfix=postfix+s.top();
			s.pop();
		}
		s.push(c[i]);
		}
		
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	cout<<postfix;
}
int main()
{
	string c;
	cout<<"Enter expression";
	getline(cin,c);
	infix_to_postfix(c,c.length());
	return 0;
}