#include <iostream>
#include<string>
using namespace std; 
const int sizee = 100;

int sum = 0;

template<class type> class Queuee
{
private:
	int front ; 
	int tail  ; 
	type  arr[sizee]; 

public:
	Queuee()
	{
		front = -1;
		tail = -1; 
	}
	void Enqueue(type val)
	{
		if (front ==-1&& tail == -1)
		{
			front++; 
			tail++; 
			arr[tail] = val; 
			sum++;
		}
		else if (front == tail == sizee - 1)
		{
			return;
		}
		else
		{
			tail++; 
			arr[tail] = val; 
			sum++;
		}
	}
	bool isEmpty()
	{
		if (front ==-1 && tail == -1)
			return true;
		else
			return false; 
	}
	void Dequque()
	{
		if (isEmpty())
		{
			return; 
		}
		else if (front == tail )
		{
			front = -1;
			tail = -1; 
			sum--;

		}
		else
		{
			front++; 
			sum--;
		}
	}

	

	type Frontt()
	{
		if (isEmpty())
			 return-1;

		else
		{
			return arr[front]; 
		}

	}



};
int main()
{

	Queuee<char>q;


	for (int i = 1; i <= 10; i++)
	{
		char a; 
		cin >> a; 
		q.Enqueue(a); 
	}

	
	while (!q.isEmpty())
	{
		cout<<q.Frontt()<<" ";
		q.Dequque();
	}

	







	system("pause");
	return 0; 

}
