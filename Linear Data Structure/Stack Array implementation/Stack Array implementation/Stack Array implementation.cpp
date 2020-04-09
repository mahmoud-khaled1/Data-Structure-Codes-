#include <iostream>
using namespace std; 
const int maxx = 500; 

template< class type> class Stackk
{
private :
	int top; 
	type arr[maxx]; 

public:
	Stackk()
	{
		top = -1; 
	}

	void push(type value)
	{
		if (isfill())
			return;
		else
		{
			top++; 
			arr[top] = value;
		}
	}
	bool isEmpty()
	{
		return (top == -1) ? 1 : 0; 
	}
	bool isfill()
	{
		return (top == maxx - 1) ? 1 : 0;
	}

	void pop()
	{
		if (isEmpty())
			return; 
		else
		{
			top--; 
		}
	}
	type topp()
	{
		return arr[top];
	}

};

int main()
{
	Stackk<int>sta;

	for (int i = 1; i <= 10; i++)
	{
		sta.push(i); 
	}


	while (!sta.isEmpty())
	{
		cout << sta.topp() << " ";
		sta.pop();
	}





	system("pause"); 
	return 0; 
}

