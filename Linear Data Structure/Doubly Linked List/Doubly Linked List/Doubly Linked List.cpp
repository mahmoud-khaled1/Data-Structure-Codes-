#include <iostream>
using namespace std; 

template<class type>class DoublyLinkedList 
{

private:

	struct Node
	{
		type data;
		Node* next;
		Node* pre;

		Node()
		{
			next = NULL;
			pre = NULL;
		}
		

	};
	Node* head = NULL;

public:

	void Append(type val)
	{
		Node* newnode = new Node;
		newnode->data = val;
		
		
		if (head == NULL)
		{
			head = newnode;

		}
		else
		{
			Node* temp = head;
			

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->pre = temp;
		}
	}
	void insertpos(int pos, type val)
	{
		Node* newnode = new Node; 
		newnode->data = val; 

		if (head == NULL)
		{
			head = newnode;
			return; 
		}

		if (pos == 0)
		{
			newnode->next = head; 
			head->pre = newnode; 
			head = newnode; 
			return; 
		}
		Node* temp=head; 
		for (int i = 0; i < pos && temp != NULL; i++)
		{
			temp = temp->next; 
		}
		if (temp == NULL)
		{
			this->Append(val); 

		}
		else
		{
			temp->pre->next = newnode; 
			newnode->pre = temp->pre; 
			newnode->next = temp;
			temp->pre = newnode; 
		}
	}
	void remove(type val)
	{
		if (head == NULL)
			return;
		
		if (head->data == val)
		{
			head = head->next; 
			if (head != NULL)
			{
				head->pre = NULL; 
			}
			else
			{
				return;
			}
		}

		Node* temp = head;

		while (temp->data != val && temp != NULL)
		{
			temp = temp->next; 
		}
		if (temp == NULL)
		{
			return; 
		}
		else
		{
			temp->pre->next = temp->next; 
			if (temp->next) {
				temp->next->pre = temp->pre;
			}

		}

	}
	void disply()
	{
		Node* temp = head; 

		while (temp != NULL)
		{
			cout << temp->data << " "; 
			temp = temp->next; 
		}
		cout << endl; 
	}
	void Reverse()
	{
		Node* temp = head; 
		while (temp->next != NULL)
		{
			temp = temp->next; 
		}

		while (temp!= NULL)
		{
			cout << temp->data << " ";
			temp = temp->pre; 
		}
	}


};
int main()
{

	DoublyLinkedList<int>L; 

	L.Append(1);
	L.Append(2);
	L.Append(3);
	L.Append(4);
	L.Append(5);
	L.Append(6);
	L.Append(7);
	L.Append(8);
	L.Append(9);
	L.Append(10);
	L.Append(11);
	L.remove(11);

	L.disply();
	L.Reverse();




	system("pause"); 
	return 0;

}


