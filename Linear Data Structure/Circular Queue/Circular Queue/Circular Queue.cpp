#include <iostream>
using namespace std; 
const int sizee = 200;

template<class type> class Queuee {

private:
	int front;
	int tail; 
	type arr[sizee]; 

public :
	Queuee()
	{
		front = -1;
		tail = -1; 
	}

	void Enqueue(type val)
	{
		if (front == -1 && tail == -1)
		{
			tail++;
			front++; 
			arr[tail] = val; 

		}
		else if ((tail+1)%sizee==front)
		{
			return; 
		}
		else
		{
			tail = (tail + 1) % sizee;
			arr[tail] = val; 
		}
	}
	void Dequeue()
	{
		if (front == -1 && tail == -1)
		{
			return; 
		}
		else if (front == tail)
		{
			front = -1; 
			tail = -1; 
		}
		else
		{
			front=(front+1)%sizee; 
		}
	}

	bool isEmpty()
	{
		if (tail == -1 && front == -1)
			return true;

		else
			return false; 
	}
	type Frontt()
	{
		if (isEmpty())
			return - 1;

		else
			return arr[front]; 
	}







};

int main()
{
   
	Queuee<int>q; 



	for (int i = 0; i < 10; i++)
	{
		q.Enqueue(i); 
	}


	while (!q.isEmpty())
	{
		cout << q.Frontt() << " ";
		q.Dequeue(); 
	}





	system("pause"); 
	return 0; 
}

