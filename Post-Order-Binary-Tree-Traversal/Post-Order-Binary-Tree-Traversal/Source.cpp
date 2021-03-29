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

void createTree(vector<int> preOrder, vector<int> inOrder, vector<int>& postOrder, int start, int stop, TreeNode* curr, int& iter, int& pos)
{
    //cout << iter << " " << pos << endl;
    if (start == stop)
    {

        curr->left = NULL;
        curr->right = NULL;
        postOrder[pos] = curr->label;
        pos++;
        return;
    }
    for (int i = start; i < stop; i++)
    {
        if (curr->label == inOrder[i])
        {
            //cout << "curr->label == " << inOrder[i] << endl << endl;
            if (i == start)
            {
                // curr has no left child or curr is left child? Still working it out
                // iter needs to increment
                postOrder[pos] = curr->label;
                pos++;
                return;
            }
            else if (i == stop)
            {
                // curr has no right child or curr is left child? Still working it out
                // iter needs to increment
                postOrder[pos] = curr->label;
                pos++;
                return;
            }
            else
            {
                iter++;
                curr->left = new TreeNode(preOrder[iter]);
                //cout << "Left: " << curr->left->label << endl;
                createTree(preOrder, inOrder, postOrder, start, i - 1, curr->left, iter, pos);

                iter++;
                curr->right = new TreeNode(preOrder[iter]);
                //cout << "Right: " << curr->right->label << endl;            
                createTree(preOrder, inOrder, postOrder, i + 1, stop, curr->right, iter, pos);
            }
        }
    }
    // add the curr.label to postOrder.
    //cout << curr->label << " pos = " << iter << endl;
    postOrder[pos] = curr->label;
    pos++;
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
    createTree(preorder, inorder, postorder, 0, n, root, iter, pos);

    // output the post order traversal
    for (int i = 0; i < n; i++) cout << postorder[i] << " ";
    cout << endl;
}