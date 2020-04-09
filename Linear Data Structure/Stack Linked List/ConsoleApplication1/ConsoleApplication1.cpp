#include <iostream>
using namespace std; 

template<class type>class Stackk {

private :

	struct Node
	{
		type data; 
		Node* next; 

		Node(type num)
		{
			next = NULL; 
			data = num; 
		}
	};
	Node* top=nullptr;

public:
	
	void push(type val)
	{
		Node* newnode = new Node(val); 

		newnode->data = val;

		if (top == nullptr)
		{
			newnode->next = nullptr;
			top = newnode;
		}
		else
		{
			Node* temp = top;

			newnode->next = temp; 
			top = newnode;
		}
	}
	void pop()
	{
		if (top == nullptr)
			return; 

		else
		{
			Node* temp = top;
			top = temp->next;
			delete temp; 

		}
	}
	bool isEmpty()
	{
		if (top == nullptr)
			return true;
		else
			return false; 
	}

	type topp()
	{
		if (top == NULL)
			return -1; 

		else
		{
			Node* temp = top;
			
			return temp->data; 

		}
	}


	int getsize()
	{
		Node* temp = top; 
		int sum = 0; 

		

		while (temp != NULL)
		{
			sum++; 
			temp = temp->next; 
		}
		return sum; 

	}

	void disply()
	{
		Node* temp = top;

		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next; 
		}
		cout << endl; 
	}






};
int main()
{
	Stackk<int>Sta; 

	Sta.push(1); 
	Sta.push(2);
	Sta.push(3);
	Sta.push(4);
	Sta.push(5);
	Sta.push(6);
	Sta.push(7);
	Sta.push(8);
	Sta.push(9);
	Sta.push(10);

	//Sta.disply(); 
	/*cout << Sta.topp() << endl; ;*/

	cout << "Size:" << " " << Sta.getsize() << endl;

	while (!Sta.isEmpty())
	{
		cout << Sta.topp() << " "; 
		Sta.pop(); 
	}
	cout << endl; 

	






	system("pause"); 
	return 0; 
}

