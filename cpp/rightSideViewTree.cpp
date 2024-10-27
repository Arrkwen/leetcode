/**
 * Definition for a binary tree node.
 */


#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include<queue>

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res{};
        if (root == NULL)
            return res;
        queue<TreeNode *> *p = new queue<TreeNode*>();
        p->push(root);
        TreeNode *last = root;
        TreeNode *nlast = root;
        while(!p->empty())
        {
            root = p->front();
            p->pop();
            if(root->left!=NULL)
            {
                p->push(root->left);
                nlast = root->left;
            }
            if(root->right!=NULL)
            {
                p->push(root->right);
                nlast = root->right;
            }
            if(root == last)
            {
                res.push_back(root->val);
                last = nlast;
            }
        }
        return res;
    }
};