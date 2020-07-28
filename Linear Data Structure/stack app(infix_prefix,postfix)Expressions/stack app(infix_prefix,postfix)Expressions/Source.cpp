#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std; 

int check_priority(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if (ch == '/' || ch == '*' || ch == '%')
	{
		return 2;
	}
	else if (ch == '^')
	{
		return 3;
	}

	return 0; 
}
float Math_operations(float n1, float n2, char ch)
{
	if (ch == '+')
		return n1 + n2;
	else if (ch == '-')
	{
		return n1 - n2;
	}
	else if (ch == '*')
	{
		return n1 * n2;
	}
	else if (ch == '/')
	{
		return n1 / n2;
	}

	else
	{
		return 0;
	}
}
float Evaluation_Expression(string ex)
{
	stack<float>staa;

	for (int i = 0; i < ex.length(); i++)
	{
		if (isdigit(ex[i]))
			staa.push(ex[i] - '0');
		else
		{
			float nu1 = staa.top();
			staa.pop();
			float nu2 = staa.top();
			staa.pop();

			float result = Math_operations(nu2, nu1, ex[i]);
			staa.push(result);
		}
	}

	return staa.top();
}
float infix_topostfix(string exp)
{
	string output = "";
	stack<char>sta; 

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == ' ')
		{
			continue;
		}
		if (isdigit(exp[i]) || isalpha(exp[i]))
		{
			output += exp[i];
		}
		else if (exp[i] == '(')
		{
			sta.push(exp[i]);

		}
		else if (exp[i] == ')')
		{
			while (sta.top()!='(')
			{
				output += sta.top();
			    sta.pop();
			}
			sta.pop();
		}
		else
		{
			while (!sta.empty()&&check_priority(exp[i]) <= check_priority(sta.top()))
			{
				output += sta.top();
				sta.pop();
			}
			sta.push(exp[i]);
		}
	}
	while (!sta.empty())
	{
		output += sta.top();
		sta.pop();
	}
	
	return Evaluation_Expression( output); 
}


int main()
{
	
   string infixExpression = ("(3+2)+7/2*((7+3)*2)");

   cout << infix_topostfix(infixExpression) << endl; 



	return 0; 
}