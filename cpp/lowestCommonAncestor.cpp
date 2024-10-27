/* 

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。


思路1：

递归：
1 如果根节点为空，返回空
2 如果root节点等于其中一个，返回root
3 如果都是不，递归左子树和右子树
4.1  如果左子树不为空，右子树为空，右子树没有任何一个节点，返回left的结果
4.2  如果左子树为空，右子树不为空，左子树没有任何一个节点，返回right的结果
4.2  如果左子树不为空，右子树也不为空，说明左子树找到一个节点，右子树找到一个节点，则祖先为root，返回root

思路2  递归，先序遍历，DFS找到两条路径，求公共交点。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_a, path_b;
        if (!get_path(root, p, path_a) || !get_path(root, q, path_b)) return nullptr;
        int i = 1;
        for (; i < path_a.size() && i < path_b.size(); i++) {
            if (path_a[i] != path_b[i]) return path_a[i-1];
        }
        return path_a[i-1];
    }
    bool get_path(TreeNode* root, TreeNode* a, vector<TreeNode*>& path) {
        if (!root) return false;
        path.emplace_back(root);
        if (root == a) return true;
        if (get_path(root->left, a, path)) return true;
        if (get_path(root->right, a, path)) return true;
        path.pop_back();
        return false;
    }
};
 */


#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root==p||root==q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        return root;
    }
};

class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        vector<TreeNode *> path_a, path_b;
        if(!get_path(root,p,path_a)||!get_path(root,q,path_b))
            return NULL;
        int i = 1;
        for (; i < path_a.size() && i < path_b.size();i++)
            if(path_a[i]!=path_b[i])
                return path_a[i - 1];
        return path_a[i - 1];
    }
    bool get_path(TreeNode* root, TreeNode* a, vector<TreeNode*>& path) {
        if (root == NULL)
            return false;
        path.emplace_back(root);
        //先序遍历
        if (root == a) return true;
        if(get_path(root->left,a,path))
            return true;
        if(get_path(root->right,a,path))
            return true;
        path.pop_back();
        return false;
    }
};