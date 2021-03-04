#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

bool find_path(Node* root,int value,vector<Node*> &v)
{
	if(root==NULL)
	return false;
	v.push_back(root);

	if(root->data==value)
	return true;
	if(find_path(root->left,value,v) || find_path(root->right,value,v))
	return true;

	v.pop_back();
	return false;
}

int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

	vector<Node*>v1,v2;

	if(find_path(root,27,v1)==false ||	find_path(root,25,v2)==false)
	{
	cout<<"No LCA";
	exit(0);
	}

	int flag=0;

	for(int i=0;i<v1.size()-1 && i<v2.size()-1;i++)
	{
		if(v1[i+1]->data!=v2[i+1]->data)
		{
			cout<<v1[i]->data;
			flag=1;
			break;
		}
	}
if(!flag)
cout<<"No LCA";
}