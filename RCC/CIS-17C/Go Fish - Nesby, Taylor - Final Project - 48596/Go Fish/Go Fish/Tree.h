#include <iostream>
#include <vector>
using namespace std;
class Tree
{
 private:
    struct Node
    {
        int data;
        int height;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* worker;
public:
    //constructor
    Tree()
    {
        root=NULL;
    }
    //destructor
    ~Tree()
    {
        freeNode(root);
    }
    //frees the node
    void freeNode(Node* leaf)
    {
        if ( leaf != NULL )
        {
            freeNode(leaf->left);
            freeNode(leaf->right);
            delete leaf;
        }
    }
    //inserts a new leaf to the tree
    void insertLeaf(int v)
    {
        if(root==NULL)
            root=createLeaf(v);
        insertLeaf(root,v);
    }
    //to add a node
    void insertLeaf(Node* n, int v)
    {
        //Check if tree is empty
        if(n==NULL)
            n=createLeaf(v); //add leaf
        else if(v<=n->data)
        {
            //If it is pointing to something already (recursive)
            if(n->left!=NULL)
            {
                insertLeaf(n->left,v);
            }
            //If it is not pointing to anything
            else
            {
                n->left=createLeaf(v);
                //balance
                balanceLeft(n,v);
            }
        }  
        else if(v>n->data)
        {
             //If it is pointing to something already (recursive)
            if(n->right!=NULL)
            {
                insertLeaf(n->right,v);
            }
            //If it is not pointing to anything
            else
            {
                n->right=createLeaf(v);
                //balance
                balanceRight(n,v);
            }
        }
        n->height = max(height(n->left), height(n->right)) + 1;
    }
    //prints the tree data
    vector<int> high(int c)
    {
		vector<int> highScores;
        if(root!=NULL)
        {
            switch(c)
            {
                case 1:
                    highScores=preOrder(root);
                    break;
                case 2:
                    highScores=postOrder(root);
                    break;
                case 3:
                    highScores=inOrder(root);
					break;
            }
        }
		return highScores;
    }
    //creates a new node(leaf)
    Node* createLeaf(int v)
    {
        Node* temp=new Node;
        temp->data=v;
        temp->height=0;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    //gets height of the node
    int height(Node *n)
    {
        return n == NULL ? -1 : n->height;
    }
    void balanceLeft(Node *n, int v)
    {
        if (height(n->left) - height(n->right) == 2)
        {
            if (v < n->left->data)
                n = rotateWithLeftChild(n);
            else
                n = doubleWithLeftChild(n);
        }
    }
    void balanceRight(Node *n, int v)
    {
        if (height(n->right) - height(n->left) == 2)
        {
            if (v > n->right->data)
                n = rotateWithRightChild(n);
            else
               n = doubleWithRightChild(n);
        }  
    }
    //rotate tree node with left child
    Node *rotateWithLeftChild(Node* k2)
    {
        Node *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        return k1;
    }
    //rotate tree node with right child
    Node *rotateWithRightChild(Node *k1)
    {
        Node *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        return k2;
    }
    //double rotate
    Node *doubleWithLeftChild(Node *k3)
    {
        k3->left = rotateWithRightChild(k3->left);
        return rotateWithLeftChild(k3);
    }
    //double rotate
    Node *doubleWithRightChild(Node *k1)
    {
        k1->right = rotateWithLeftChild(k1->right);
        return rotateWithRightChild(k1);
    }
    //pre order transversal
    vector<int> preOrder(Node* n)
    {
		vector<int> highScores;
        if(n)
        {
            highScores.push_back(n->data);
            preOrder(n->left);
            preOrder(n->right);
        }
		return highScores;
    }
    //post order transversal
    vector<int> postOrder(Node* n)
    {
		vector<int> highScores;
        if (n)
        {
            postOrder(n->left);
            postOrder(n->right);
            highScores.push_back(n->data);
        }
		return highScores;
    }
    //in order transversal
    vector<int> inOrder(Node* n)
    {
		vector<int> highScores;
        if (n)
        {
            inOrder(n->left);
			highScores.push_back(n->data);
            inOrder(n->right);
        }
		return highScores;
    }
    //searches for a value in the tree
    bool search(Node *r, int v)
    {
        bool found = false;
        while ((r != NULL) && !found)
        {
            int rval = r->data;
            if (v < rval)
                r = r->left;
            else if (v > rval)
                r = r->right;
            else
            {
                found = true;
                break;
            }
            found = search(r, v);
        }
        return found;
    }
    //searches for a value in the tree-returns true if found, false if not found
    bool search(int v)
    {
        return search(root, v);
    }
    //deletes leaf and reorders
    void removeNode(int v)
    {
        removeNodep(v,root);
    }
    void removeNodep(int v, Node* parent)
    {   
        //If not empty
        if(root!=NULL)
        {
            //If found the data to delete
            if(root->data==v)
            {
                removeRootMatch();
            }
            //If not found
            else
            {
                //Left child
                if(v<parent->data&&parent->left!=NULL)
                {
                    parent->left->data==v ?
                    removeMatch(parent,parent->left,true):
                    removeNodep(v,parent->left);
                }
                //Right child
                else if(v>parent->data&&parent->right!=NULL)
                {
                    parent->right->data==v ?
                    removeMatch(parent,parent->right,false):
                    removeNodep(v,parent->right);
                }
                else
                {
                    cout<<"The data "<<v<<" was not found in the tree."<<endl;
                }
            }
        }
        //If empty
        else
        {
            cout<<"The tree is empty."<<endl;
        }
    }
    void removeRootMatch()
    {
        if(root!=NULL)
        {
            Node* delPtr=root;
            int rootData=root->data;
            int smallestright;
            //0 children
            if(root->left==NULL&&root->right==NULL)
            {
                root=NULL;
                delete delPtr;
            }
            //1 Child
            //  child on right
            else if(root->left==NULL&&root->right!=NULL)
            {
                root=root->right;
                delPtr->right=NULL;
                delete delPtr;
            }
            //  child on left
            else if(root->left!=NULL&&root->right==NULL)
            {
                root=root->left;
                delPtr->left=NULL;
                delete delPtr;
            }
            //2 Children
            else
            {
                smallestright=findsmallestp(root->right);
                removeNodep(smallestright,root);
                root->data=smallestright;
            }
        }
        else
        {
            cout<<"Can not remove root, tree is empty"<<endl;
        }
    }
	void removeMatch(Node* parent, Node* match, bool left)
    {
        if(root!=NULL)
        {
            Node* delPtr;
            int matchData=match->data;
            int smallestright;
            //0 Children
            if(match->left==NULL&&match->right==NULL)
            {
                delPtr=match;
                left==true?parent->left=NULL:parent->right=NULL;
                delete delPtr;
            }
            //1 Child
            //  Right child
            else if(match->left==NULL&&match->right!=NULL)
            {
                left==true?parent->left=match->right:parent->right=match->right;
                match->right=NULL;
                delPtr=match;
                delete delPtr;
            }
            //  Left child
            else if(match->left!=NULL&&match->right==NULL)
            {
                left==true?parent->left=match->left:parent->right=match->left;
                match->left=NULL;
                delPtr=match;
                delete delPtr;
            }
            //2 Children
            else
            {
                smallestright=findsmallestp(match->right);
                removeNodep(smallestright,match);
                match->data=smallestright;
            }
        }
        else
        {
            cout<<"Can not remove match. Tree is empty"<<endl;
        }
    }
    int findsmallestp(Node* ptr)
    {
        //If empty
        if(root==NULL)
        {
            cout<<"Tree is empty."<<endl;
            return -1000;
        }
        //When not empty
        else
        {
            if(ptr->left!=NULL)
            {
                return findsmallestp(ptr->left);
            }
            else
            {
                return ptr->data;
            }
        }
    }
	};