#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
template<class type> class BST {

private:
	struct Node
	{
		type data;
		Node* left;
		Node* right;

		Node(type val)
		{
			data = val;
			left = right = nullptr;
		}
	};

	Node* root = nullptr;


	void inserthelper(Node* temp, type val)
	{
		if (val <= temp->data)
		{
			if (temp->left == nullptr)
			{
				temp->left = new Node(val);
			}
			else
			{
				inserthelper(temp->left, val);
			}
		}
		else
		{
			if (temp->right == nullptr)
			{
				temp->right = new Node(val);
			}
			else
			{
				inserthelper(temp->right, val);

			}
		}

	}
	Node* maxxhelper(Node* temp)
	{

		if (temp == NULL)
		{
			return NULL;
		}
		else if (temp->right == nullptr)
		{
			return temp;
		}

		return maxxhelper(temp->right);

	}
	Node* minhelper(Node* temp)
	{


		///* loop down to find the leftmost leaf */
		//while (temp->left != NULL)
		   // temp = temp->left;

		if (temp == NULL)
			return NULL;

		if (temp->left == nullptr)
		{
			return temp;
		}

		return minhelper(temp->left);


	}
	int heighthelper(Node* temp)
	{
		if (temp == nullptr)
		{
			return -1;
		}
		return max(heighthelper(temp->left), heighthelper(temp->right)) + 1;
	}
	void deletehelper(Node* temp, type val, Node* pre)
	{
		if (temp->data < val)
		{
			deletehelper(temp->right, val, temp);
		}
		else if (temp->data > val)
		{
			deletehelper(temp->left, val, temp);
		}
		else
		{
			// Case 1 : No children 
			if (temp->left == NULL && temp->right == NULL)
			{

				if (pre->left->data == val)
				{
					/*free(preview->left);*/
					pre->left = NULL;
				}
				else
				{
					/*free(preview->right);*/
					pre->right = NULL;
				}


			}
			// Case 2 : 1 Children 
			else if (temp->left == NULL)
			{

				Node* temp2 = temp->right;
				temp->data = temp2->data;
				temp->left = temp2->left;
				temp->right = temp2->right;
				delete temp2;

			}
			else if (temp->right == NULL)
			{
				/*Node* temp2 = temp;

				temp = temp->left;
				delete temp2; */

				Node* temp2 = temp->left;
				temp->data = temp2->data;
				temp->left = temp2->left;
				temp->right = temp2->right;
				delete temp2;

			}
			// Case 3 : 2 Children 
			else if (temp->left != NULL && temp->right != NULL)
			{
				Node* tempp;
				tempp = maxxhelper(temp->left);
				temp->data = tempp->data;

				deletehelper(tempp, tempp->data, temp);
			}

		}
	}
	bool searchhelper(Node* temp, type val)
	{
		if (temp == nullptr)
		{
			return false;
		}
		else if (temp->data == val)
		{
			return true;
		}
		else if (temp->data < val)
		{
			searchhelper(temp->right, val);
		}
		else if (temp->data > val)
		{
			searchhelper(temp->left, val);
		}

	}
	void inorderhelper(Node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}

		inorderhelper(temp->left);
		cout << temp->data << " ";
		inorderhelper(temp->right);
	}
	void preOrderhelper(Node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		cout << temp->data << " ";
		preOrderhelper(temp->left);
		preOrderhelper(temp->right);

	}
	void postOrderhelper(Node* temp)
	{
		if (temp == nullptr)
		{
			return;
		}

		preOrderhelper(temp->left);
		preOrderhelper(temp->right);
		cout << temp->data << " ";

	}
	int check_Balanced_Helper(Node* temp)
	{
		if (!temp)
			return true;

		int leftsubtree = heighthelper(temp->left);
		int rightsubtree = heighthelper(temp->right);

		if (abs(leftsubtree - rightsubtree) > 1)
			return false;

		return check_Balanced_Helper(temp->left) && check_Balanced_Helper(temp->right);


	}

	bool is_Left_subtree_lesser(Node* temp, type val)
	{
		if (temp == NULL)
			return true;

		if (temp->data <= val &&
			is_Left_subtree_lesser(temp->left, val) &&
			is_Left_subtree_lesser(temp->right, val))
			return true;
		else
		{
			return false;
		}

	}
	bool is_right_subtree_greater(Node* temp, type val)
	{
		if (temp == NULL)
			return true;

		if (temp->data > val&&
			is_right_subtree_greater(temp->left, val) &&
			is_right_subtree_greater(temp->right, val))
			return true;
		else
		{
			return false;
		}

	}
	bool check_if_BST_or_Not_firstway_helper(Node* temp)
	{
		if (temp == NULL)
			return true;
		else
		{
			if (is_Left_subtree_lesser(temp->left, temp->data) &&
				is_right_subtree_greater(temp->right, temp->data) &&
				check_if_BST_ot_Not_firstway_helper(temp->left, temp->left - data) &&
				check_if_BST_ot_Not_firstway_helper(temp->right, temp->right - data))
			{
				return true;
			}
			else
			{
				return false;
			}
		}



	}
	bool check_if_BST_or_Not_secondway_helper(Node* temp)
	{
		if (temp == NULL)
			return true;
		else
		{
			if (maxxhelper(temp->left) <= temp->data &&
				minhelper(temp->right) > temp->data&&
				check_if_BST_or_Not_secondway_helper(temp->left) &&
				check_if_BST_or_Not_secondway_helper(temp->right))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}



public:
	void insert(int val)
	{
		Node* newnode = new Node(val);

		if (root == nullptr)
		{
			root = newnode;
			return;
		}

		inserthelper(root, val);

		//Node* temp = root;
		//Node* parent = temp;

		//without Recursion ^_^
		/*while (temp != nullptr)
		{
			parent = temp;

			if (val <= temp->data)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		if (val <= parent->data)
		{
			parent->left = newnode;
		}
		else
		{
			parent->right = newnode;
		}
	}*/
	}
	int maxxnum()
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{

			return  maxxhelper(root)->data;
		}
	}
	int minnnum()
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{
			Node* tt;
			tt = minhelper(root);
			return tt->data;
		}
	}
	int height()
	{
		if (root == nullptr)
			return -1;
		else
		{
			return heighthelper(root);
		}
	}
	bool searchh(type val)
	{
		if (root == nullptr)
			return false;
		else
		{
			return searchhelper(root, val);

		}
	}
	void deletee(type val)
	{
		if (root == nullptr)
		{
			return;
		}

		deletehelper(root, val, root);


	}
	void displsay_Level_order()
	{
		if (root == nullptr)
			return;
		else
		{
			queue<Node*>q;
			q.push(root);

			while (!q.empty())
			{
				Node* current = q.front();
				q.pop();

				cout << current->data << "  ";

				if (current->left != nullptr)
				{
					q.push(current->left);
				}
				if (current->right != nullptr)
				{
					q.push(current->right);
				}

			}
			cout << endl;


		}
	}
	void display_preOrder()
	{
		if (root == nullptr)
		{
			return;
		}
		preOrderhelper(root);

		cout << endl;


	}
	void display_inOrder()
	{
		if (root == nullptr)
		{
			return;
		}

		inorderhelper(root);
		cout << endl;
	}
	void display_postOrder()
	{
		if (root == nullptr)
		{
			return;
		}
		postOrderhelper(root);
		cout << endl;
	}
	int NumOfNodes()
	{
		if (root == NULL)
			return -1;

		int nu = 0;

		queue<Node*>qu;

		qu.push(root);


		while (!qu.empty())
		{
			Node* current = qu.front();
			qu.pop();
			nu++;

			if (current->left != NULL)
			{
				qu.push(current->left);
			}
			if (current->right != NULL)
			{
				qu.push(current->right);
			}

		}

		return nu;


	}
	int Num_Of_Leaf_Node()
	{
		if (root == NULL)
		{
			return -1;
		}

		int num = 0;

		queue<Node*>qq;

		qq.push(root);


		while (!qq.empty())
		{
			Node* current = qq.front();
			qq.pop();


			if (current->left == NULL && current->right == NULL)
			{
				num++;
			}

			if (current->left != NULL)
			{
				qq.push(current->left);
			}
			if (current->right != NULL)
			{
				qq.push(current->right);
			}
		}
		return num;

	}
	bool check_Balanced()
	{
		if (root == NULL)
			return true;
		else
		{
			if (check_Balanced_Helper(root))
				return true;
			else
				return false;


		}
	}
	bool check_if_BST_ot_Not_firstway()
	{
		if (check_if_BST_or_Not_firstway_helper(root))
			return true;
		else
			return false;
	}

};


int main()
{

	BST<int> obj;

	obj.insert(15);
	obj.insert(10);

	obj.insert(12);
	//obj.insert(13);
	obj.insert(20);
	obj.insert(16);
	/*obj.insert(14);*/
	/*obj.insert(17);*/




	cout << obj.check_Balanced() << endl;
	/*obj.insert(6);
	obj.insert(7);
	obj.insert(8);
	obj.insert(9);*/







	/*
	obj.deletee(5);*/


	/*cout << obj.NumOfNodes() << endl;

	cout << obj.Num_Of_Leaf_Node() << endl;*/
	/*
		cout << obj.maxxnum() << endl;

		cout << obj.minnnum() << endl;

		cout << obj.height() << endl; */

		/*obj.displsay_Level_order();*/

		/*obj.display_inOrder(); */

		/*obj.display_postOrder();
		obj.display_preOrder(); */



	system("pause");
	return 0;
}


