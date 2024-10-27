#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        int method1 = root->val;
        if(root->left!=NULL)
            method1 += rob(root->left->left) + rob(root->left->right);
        if(root->right!=NULL)
            method1 += rob(root->right->left) + rob(root->right->right);
        return max(method1, rob(root->left) + rob(root->right));
    }
};

//¸Ä½ø
class Solution1 {
public:
    int rob(TreeNode* root) {
        vector<int> res(2, 0);
        res = rob1(root);
        return max(res[0], res[1]);
    }

    vector<int> rob1(TreeNode* root)
    {
        vector<int> res(2, 0);
        if(root==NULL)
            return res;
        vector<int> leftChild(2, 0);
        vector<int> rightChild(2,0);
        leftChild = rob1(root->left);
        rightChild = rob1(root->right);

        res[0] = max(leftChild[0], leftChild[1]) + max(rightChild[0], rightChild[1]);
        res[1] = leftChild[0] + rightChild[0] + root->val;

        return res;
    }
};

