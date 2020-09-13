/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

int min = INT32_MIN;
int max = INT32_MAX;
    bool isBST(Node* root,int min,int max)
    {
        if (root == NULL) return true;
        if (root->data <= min || root->data >= max)
            return false;
        
        bool l = isBST(root->left,min,root->data);
        bool r = isBST(root->right,root->data,max);
        if (l==true && r==true)
            return true;
        else
            return false;
        
    }
	bool checkBST(Node* root) {
        
        return (isBST(root,min,max));
        
        
	}