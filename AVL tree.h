#pragma once
#include"Libraries.h"

class AVL
{
public:
	Book data;
	int height;
	AVL* left;
	AVL* right;

	AVL(Book set)
	{
		this->data = set;
		this->height = 1;
		this->left = this->right = NULL;
	}
};

int height(AVL* p)
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return p->height;
	}
}

AVL* successor(AVL* root)
{
	AVL* temp = root;
	while (temp->left != NULL && temp)
	{
		temp = temp->left;
	}
	return temp;
}

int Balance(AVL* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return (height(root->left)) - (height(root->right));
	}
}

AVL* RR(AVL* root)
{
	AVL* x = root->left;
	AVL* y = x->right;

	x->right = root;
	root->left = y;

	x->height = max(height(x->left), height(x->right)) + 1;
	root->height = max(height(root->left), height(root->right)) + 1;

	return x;
}

AVL* LR(AVL* root) {
	AVL* x = root->right;
	AVL* T2 = x->left;

	x->left = root;
	root->right = T2;

	root->height = max(height(root->left), height(root->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

AVL* insert(Book val, AVL* root)
{
	if (root == NULL)
	{

		return new AVL(val);
	}
	if (val.id < root->data.id)
	{
		root->left = insert(val, root->left);
	}
	else if (val.id > root->data.id)
	{
		root->right = insert(val, root->right);
	}
	else
	{
		//root->left = insert(val, root->left);
		return root;
	}


	root->height = max(height(root->left), height(root->right)) + 1;

	int balance_Factor = Balance(root);

	//Left case
	if (balance_Factor > 1)
	{
		if (val.id < root->left->data.id)
		{
			root = RR(root);
		}
	}
	//Right case
	if (balance_Factor < -1)
	{
		if (val.id > root->right->data.id)
		{
			root = LR(root);
		}
	}
	//Left Right case
	if (balance_Factor > 1)
	{
		if (val.id > root->left->data.id)
		{
			root->left = LR(root->left);
			root = RR(root);
		}
	}
	//Right Left case
	if (balance_Factor < -1)
	{
		if (val.id < root->right->data.id)
		{
			root->right = RR(root->right);
			root = LR(root);
		}
	}

	return root;
}

AVL* delete_node(int val, AVL* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (val < root->data.id)
	{
		root->left = delete_node(val, root->left);
	}
	else if (val > root->data.id)
	{
		root->right = delete_node(val, root->right);
	}
	else
	{
		if (root->left == NULL)
		{
			AVL* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			AVL* temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			AVL* temp = successor(root->right);
			root->data = temp->data;
			root->right = delete_node(temp->data.id, root->right);

		}
	}

	if (root == NULL)
	{
		return root;
	}

	int BalanceFactor = Balance(root);

	if (BalanceFactor > 1)
	{
		if (height(root->left) > -1)
			root = RR(root);
	}

	// Left Right Case 
	if (BalanceFactor > 1)
	{
		if (height(root->left) <= -1)
			root->left = LR(root->left),
			root = RR(root);
	}

	// Right Right Case 
	if (BalanceFactor < -1)
		if (height(root->right) < 1)
			root = LR(root);

	// Right Left Case 
	if (BalanceFactor < -1)
	{
		if (height(root->right) > 0)
			root->right = RR(root->right),
			root = LR(root);
	}

	return root;
}


//Point searchs
void AVLPointSearchID(AVL* p, int key)
{
	if (p != 0)
	{
		if (p->data.id == key) {
			p->data.display();
			return;
		}
		AVLPointSearchID(p->left, key);
		AVLPointSearchID(p->right, key);

	}

}

//Ranger searchs
void AVLRangeSearchID(AVL* p, int low, int high)
{
	if (p != 0)
	{
		AVLRangeSearchID(p->left, low, high);
		if (p->data.id >= low && p->data.id <= high) {
			p->data.display();
		}
		AVLRangeSearchID(p->right, low, high);
	}
}

//Traversals
void AVLPostOrderTransversal(AVL* p)
{

	if (p != 0)
	{


		AVLPostOrderTransversal(p->left);
		AVLPostOrderTransversal(p->right);
		p->data.display();

	}
}

void AVLInOrderTransversal(AVL* p)
{
	if (p != 0)
	{

		AVLInOrderTransversal(p->left);

		p->data.display();

		AVLInOrderTransversal(p->right);

	}
}

void AVLPreOrderTransversal(AVL* p)
{
	if (p != 0)
	{

		p->data.display();

		AVLPreOrderTransversal(p->left);
		AVLPreOrderTransversal(p->right);

	}
}

//borrow
void borrow(AVL* p, int key)
{
	if (p != 0)
	{
		if (p->data.id == key) {
			p->data.avaliable = false;
			return;
		}
		borrow(p->left, key);
		borrow(p->right, key);

	}
}

//return
void returning(AVL* p, int key)
{
	if (p != 0)
	{
		if (p->data.id == key) {
			p->data.avaliable = true;
			return;
		}
		returning(p->left, key);
		returning(p->right, key);

	}
}

