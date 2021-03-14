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


    Node* lca(Node* root ,int a ,int b )
    {
      vector<Node*> v1,v2;
  	if(find_path(root,a,v1)==false||find_path(root,b,v2)==false)
	return NULL;

    int i;
	for( i=0;i<v1.size()-1 && i<v2.size()-1;i++)
	{
		if(v1[i+1]->data!=v2[i+1]->data)
		{
            break;
		}
	}
    return v1[i]; 
    }
