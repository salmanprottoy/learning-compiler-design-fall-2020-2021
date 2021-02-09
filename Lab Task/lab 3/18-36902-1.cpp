#include<iostream>
#include<algorithm>
using namespace std;

typedef struct tree
{
    tree *left, *right;
    char data;
}*nodeTree;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

nodeTree makeNode(char value)
{
	nodeTree newNode = new(tree);
	if(newNode == NULL)
	{
		cout<<"Out of memory!"<<endl;
		return 0;
	}
	else
	{
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	return newNode;
}

nodeTree insert_node(nodeTree ptr, char value)
{
	if(ptr == NULL)
	{
		ptr = makeNode(value);
	}
	else if(value!='=' || value!='+' || value!='-' || value!='*' || value!='/')
	{
		ptr->left = insert_node(ptr->left,value);
	}
	else
	{
		ptr->right = insert_node(ptr->right,value);
	}
	return ptr;
}

void inorder(nodeTree ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<ptr->data<<" ";
		inorder(ptr->right);
	}
}

void preorder(nodeTree ptr)
{
    if(ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(nodeTree ptr)
{
     if(ptr!= NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<" ";
    }
}

int main()
{
    nodeTree root = NULL, temp;
    string str;
    cout<<"Input: ";
    getline(cin,str);
    cout<<endl;
    str=removeSpaces(str);
    for(int i=0;i<str.length();i++)
    {
        temp = root;
        if (root == NULL)
            root = insert_node(root,str[i]);
        else
            temp = insert_node(temp,str[i]);
    }
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
    return 0;
}
