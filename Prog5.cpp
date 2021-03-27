
#include <iostream>
#include <vector>
using namespace std; 

typedef struct TreeNode
{
	int label; 
	TreeNode *left, *right; 
} TreeNode; 


// Build the tree out based off the two vectors. This may not be the most efficient approach. There is most likely a way to
// print out post-order without creating the whole tree.

void createTree(vector<int> preOrder, vector<int> inOrder, vector<int> &postOrder, int start, int stop, TreeNode curr, int iter)
{
    if (start == stop)
    {
        curr->left = NULL;
        curr->right = NULL;
    }
    for (int i = start; i < stop; i++)
    {
        if (curr.label == inOrder[i])
        {
            if (i == start)
            {
                // curr has no left child or curr is left child? Still working it out
                // iter needs to increment
            }
            else if (i == stop)
            {
                // curr has no right child or curr is left child? Still working it out
                // iter needs to increment
            }
            else
            {
                iter++;
                curr->left = new TreeNode(preOrder[iter]);
                createTree(preOrder, inOrder, postOrder, start, i - 1, curr->left, iter);
                iter++;
                curr->right = new TreeNode(preOrder[iter]);
                createTree(preOrder, inOrder, postOrder, i + 1, curr->right, iter);
            }
        }
    }
    // add the curr.label to postOrder.
}

int main()
{
	int n; 
	cin >> n; 

	vector<int> preorder(n); 
	for(int i=0; i<n; i++) cin >> preorder[i]; 
	vector<int> inorder(n); 
	for(int i=0; i<n; i++) cin >> inorder[i];
	vector<int> postorder(n, -1);
    TreeNode root = new TreeNode(preorder[0]);

    for (int i = 0; i < n; i++)
    {
        cout << postorder[i];
    }

	// compute your post order traversal in postorder!
    // createTree(preorder, inorder, postorder, 0, n, root);

	// output the post order traversal
	for(int i=0; i<n; i++) cout << postorder[i] << " "; 
	cout << endl; 
}