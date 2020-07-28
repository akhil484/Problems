#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<int> s;
bool isOperator(char c)
{
	if(c=='+'||c=='*'||c=='-'||c=='/')
		return true;
	else
		return false;
}
bool isNumber(char c)
{
	if(c>='0'&&c<='9')
		return true;
	else
		return false;
}
int evaluate_expr(int op1,int op2,char c)
{
	if(c=='+')
		return op1+op2;
	else if(c=='-')
		return op2-op1;
	else if(c=='*')
		return op1*op2;
	else if(c=='/')
		return op2/op1;
}
int main()
{
	string c;
	int op1,op2,res;
	cout<<"Enter expression";
	getline(cin,c);
	for(int i=0;i<c.length();i++)
	{
		if(c[i]==' '||c[i]==',')
			continue;
		else if(isOperator(c[i]))
		{
			op2=s.top();
			s.pop();
			op1=s.top();
			s.pop();
			res=evaluate_expr(op1,op2,c[i]);
			s.push(res);
		}
		else if(isNumber(c[i]))
		{
			int operand=0;
			while(i<c.length()&&isNumber(c[i])){
				operand=(operand*10)+(c[i]-'0');
				i++;
			}
			i--;
			s.push(operand);
		}
	}
	cout<<s.top();

}