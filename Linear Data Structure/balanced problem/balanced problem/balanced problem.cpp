#include <iostream>
#include<stack>
#include<string>
using namespace std; 

int main()
{
	string s; 
	cin >> s; 
	stack< char >sta; 

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			sta.push(s[i]); 

		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (!sta.empty())
			{
				if ((s[i] == ')' && sta.top() == '(')||(s[i]==']'&&sta.top()=='[')||(s[i]=='}'&&sta.top()=='{'))
				{
					sta.pop();
				}
			}
			else
			{
				cout << "Error" << endl; 
				return 0;
			}
		}
		else
		{
			cout << "Erorr" << endl; 
			return 0;
		}
	}


	if (sta.empty())
		cout << "correct" << endl;
	else
		cout << "Error" << endl; 

	system("pause"); 
	return 0; 
}


