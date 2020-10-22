bool abc(Node *root,int n,vector<Node*> &v)
{
 if(root==NULL)
 return false;
 v.push_back(root);
 if(root->data==n)
 return true;
 if((root->left && abc(root->left,n,v))||(root->right && abc(root->right,n,v)))
 {
     return true;
 }
 v.pop_back();
 return false;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
 vector<Node * >v1,v2;
  if ( abc(root,n1,v1)==false || abc(root,n2,v2)==false) 
          return NULL; 
  
    
int i; 
    for (i = 0; i < v1.size() && i < v2.size() ; i++) 
        if (v1[i] !=v2[i]) 
            break; 
    return v1[i-1]; 
}
