#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode
{
    int label;
    TreeNode* left, * right;
    TreeNode(int i) : label(i), left(nullptr), right(nullptr) {};
} TreeNode;


// Build the tree out based off the two vectors. This may not be the most efficient approach. There is most likely a way to
// print out post-order without creating the whole tree.

void createTree(vector<int> preOrder, vector<int> inOrder, vector<int>& postOrder, int start, int stop, TreeNode* curr, int& iter, int& pos, int len)
{
    // A base case for this recurion is that if you are on the last number of preOrder array, then you can't go any further.
    // Add the number to the post-order.
    if (iter == len)
    {
        postOrder[pos] = curr->label;
        pos++;
        return;
    }
    // The second base case is if the start and stop is equal then you add the current nodes value to the post-order vector.
    else if (start == stop)
    {
        postOrder[pos] = curr->label;
        pos++;
        return;
    }
    else
    {
        for (int i = start; i <= stop; i++)
        {
            if (curr->label == inOrder[i])
            {
                if (i == start)
                {
                    // curr node cannot have a left child since it is at the beginning of the list. Only continue with right child.
                    // iter needs to increment
                    iter++;
                    curr->right = new TreeNode(preOrder[iter]);
                    createTree(preOrder, inOrder, postOrder, i + 1, stop, curr->right, iter, pos, len);
                    break;
                }
                else if (i == stop)
                {
                    // curr node cannot have right child since it is at the end of the list. Continue with left child.
                    // iter needs to increment
                    iter++;
                    curr->left = new TreeNode(preOrder[iter]);
                    createTree(preOrder, inOrder, postOrder, start, i - 1, curr->left, iter, pos, len);
                    break;
                }
                else
                {
                    // Curr node is in the middle of the inOrder list so it has both a left and right child.
                    iter++;
                    curr->left = new TreeNode(preOrder[iter]);
                    createTree(preOrder, inOrder, postOrder, start, i - 1, curr->left, iter, pos, len);

                    iter++;
                    curr->right = new TreeNode(preOrder[iter]);
                    createTree(preOrder, inOrder, postOrder, i + 1, stop, curr->right, iter, pos, len);
                    break;
                }
            }
        }
        // add the curr.label to postOrder.
        postOrder[pos] = curr->label;
        pos++;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> preorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    vector<int> inorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    vector<int> postorder(n, -1);


    // compute your post order traversal in postorder!
    TreeNode* root = new TreeNode(preorder[0]);
    int iter = 0;
    int pos = 0;
    createTree(preorder, inorder, postorder, 0, n - 1, root, iter, pos, n - 1);

    // output the post order traversal
    for (int i = 0; i < n; i++) cout << postorder[i] << " ";
    cout << endl;
}