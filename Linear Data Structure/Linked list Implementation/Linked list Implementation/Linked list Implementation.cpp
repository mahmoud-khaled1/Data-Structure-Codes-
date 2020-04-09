#include <iostream>
using namespace std; 

template<class type> class Linked_List {

private:

	struct Node
	{
		type data; 
		Node* next=NULL; 
	};
	
	Node* head=NULL; 

public:

	/*Linked_List()
	{
		next = NULL; 
		head = NULL; 
	}*/
	void Append(type value)
	{
		Node* newnode = new Node;

		
		newnode->data = value;
		newnode->next = NULL;

		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			Node* temp;
			temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;

			//delete temp;
		}
	}

	void remove(type value)
	{
		if (head == NULL)
		{
			return;
		}

		Node* temp ;
		Node* pre ;
		temp = head;
		pre = head;

	
		if (temp->data == value)
		{
			head = temp->next;
			delete temp;
			return;

		}
		
			while (temp!=NULL&& temp->data != value)
			{
				pre = temp;
				temp = temp->next; 
			}

			if (temp == NULL)
			{
				return; 
			}
			else
			{
				pre->next = temp->next;
				delete temp;
			}

	


	}

	void insertpos(type val, int pos)
	{
		if (head == NULL)
		{
			return;
		}
		int a = 1;
		Node* temp, * pre; 
		Node* newnode = new Node; 
		newnode->data = val; 
		newnode->next = NULL; 

		temp = head; 
		pre = head; 

		if (pos == 1)
		{
			head = newnode; 
			head->next = temp;
		}
		else 
		{
			while (a != pos&&temp!=NULL)
			{
				pre = temp; 
				temp = temp->next; 
				a++;
			}
			pre->next = newnode; 
			newnode->next = temp; 
		}
	}

	void removepos(int pos)
	{
		int a = 1; 
		if (head == NULL)
		{
			return; 
		}
		Node* temp, * pre; 
		temp = pre = head; 

		if (pos == 1)
		{
			head = temp->next; 
		}
		else
		{
			while (a != pos && temp != NULL)
			{
				pre = temp;
				temp = temp->next; 
				a++; 
			}
			if (temp != NULL)
			{
				pre->next = temp->next;
				delete temp;
			}
			else
			{
				return; 
			}
		}
	}

	void disply()
	{

		Node* temp; 

		temp = head; 

		while (temp != NULL)
		{
			cout << temp->data <<" ";
			temp = temp->next;
		}
		cout << endl; 
	}

	void Reverse()
	{
		if (head == NULL)
		{
			return;
		}
		Node* pre=NULL;
		Node* cur=head;
		Node* next=NULL;

		while (cur != NULL)
		{
			next = cur->next; 
			cur->next = pre; 
			pre = cur; 
			cur = next; 
		}

		head = pre; 

	}

	void displyEven()
	{
		if (head == NULL)
		{
			return;
		}

		Node* temp = new Node;
		temp = head; 

		while (temp != NULL)
		{
			if (temp->data % 2 == 0)
			{
				cout << temp->data << " ";
				
			}
			temp = temp->next;
			
		}
		cout << endl;
	

	}
	
	void sortt()
	{
		Node* temp = head; 


		if (head == NULL)
			return; 

		int numofnode = 0; 

	    while(temp!=NULL)
		{ 
			numofnode++; 
			temp = temp->next; 
		}


		temp = head; 
		Node* pre = NULL;
		int n = 0;

		for (int i = 0; i < numofnode; i++)
		{
			while (temp->next)  
			{
				if (temp->data > temp->next->data)
				{
					n = temp->data;
					temp->data = temp->next->data;
					temp->next->data = n;
				}
	
					temp= temp->next;
			}
			temp = head;
		}
		
	}




};

int main()
{

	Linked_List<int> l;

	l.Append(11547); 
	l.Append(2); 
	l.Append(30);
	l.Append(454);
	l.Append(9);
	l.Append(66);
	l.Append(70);
	l.Append(88);
	l.Append(9);
	l.Append(101);

	l.disply();
	
	l.sortt(); 

	l.disply(); 

	l.Reverse();

	l.disply();


	system("pause");
	return 0; 

}


