#include <iostream>
#include <vector>
using namespace std;
 

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution 
{
public:
    vector<int> result;

    void dst(TreeNode *node)
    {
        if(node == NULL)
            return;
        else
        {
            dst(node->left);
            dst(node->right);
            result.push_back(node->val);
        }
    }

    vector<int> postorderTraversal(TreeNode *root) 
    {
        dst(root);
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}