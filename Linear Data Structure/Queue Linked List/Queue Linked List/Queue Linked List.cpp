#include <iostream>
using namespace std; 


template<class type>class Queuee {
private:
	struct Node
	{
		type data; 
		Node* next=NULL; 

	};

	Node* head = nullptr;
	Node* tail = nullptr; 

public:
	void Enqueue(type val)
	{
		Node* newnode = new Node; 
		newnode->data = val; 

		if (head == nullptr && tail == nullptr)
		{
			head = newnode; 
			tail = newnode; 
		}
		else
		{
			tail->next = newnode; 
			tail = newnode; 
		}
	}
	void Dequeue()
	{
		if (head == nullptr && tail == nullptr)
			return; 

		else
		{
			Node* temp = head; 

			if (head == tail)
			{
				head = tail = nullptr; 
			}
			else
			{

				head = temp->next;

			}

			delete temp;
		}
	}
	bool isEmpty()
	{
		if (tail == nullptr && head == nullptr)
			return true;
		else
			return false;
	}
	type front()
	{
		if (head == nullptr && tail == nullptr)
			return -1; 

		else
		{
			return head->data; 

		}
	}

	 





};
int main()
{
	Queuee<int>Q; 

	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);
	Q.Enqueue(4);
	Q.Enqueue(5);
	Q.Enqueue(6);
	Q.Enqueue(7);
	Q.Enqueue(8);
	Q.Enqueue(9);
	Q.Enqueue(10);
	Q.Enqueue(11);

	while (!Q.isEmpty())
	{
		cout << Q.front() << " ";
		Q.Dequeue(); 
	}


	system("pause"); 
	return 0; 
}

