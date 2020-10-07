#include<iostream>
 
using namespace std;
 
// tree structure
struct node
{
	int data;
	node *left;
	node *right;
};
 
// creating nodes
node* CreateNode(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
 
	return newnode;
}
 
// inserting nodes
node* InsertIntoTree(node* root, int data)
{

	node *temp = CreateNode(data);
	node *t = new node;
	t = root;
 
	
	if(root == NULL)
		root = temp;
	else	
	{
		
		while(t != NULL)
		{
			if(t->data < data )
			{
				if(t->right == NULL)
				{
					
					t->right = temp;
					break;
				}
				
				t = t->right;
			}
 
			else if(t->data > data)
			{
				if(t->left == NULL)
				{
					
					t->left = temp;
					break;
				}
			
				t = t->left;
			}
		}
	}
	return root;
}
 
// searching given node
void Search(node *root, int data)
{
	int depth = 0;
	node *temp = new node;
	temp = root;
	
	while(temp != NULL)
	{
		depth++;
		if(temp->data == data)
		{
			cout<<"Data found at depth:"<<depth<<"\n";
			return;
		}
		
		else if(temp->data > data)
			temp = temp->left;
		
		else
			temp = temp->right;
	}
 
	cout<<"Data not found\n";
	return;
}
 
 
int main()
{

	int n, i;
    int size;
    cout<<"Enter Size\n";
    cin>>size; 
    int a[size];
	node *root = new node;
	root = NULL;
    cout<<"Enter Elements\n";
	for(i = 0; i < size; i++)
    {   
		cin>>a[i];
    }
	for(i = 0; i < size; i++)
    {   
		root = InsertIntoTree(root, a[i]);
    }
 
	
	cout<<"\nEnter the Element to be searched: ";
	cin>>n;
 
	Search(root, n);
 
	

 
	return 0;
}