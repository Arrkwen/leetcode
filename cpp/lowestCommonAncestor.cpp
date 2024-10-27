/* 

����һ��������, �ҵ�����������ָ���ڵ������������ȡ�


˼·1��

�ݹ飺
1 ������ڵ�Ϊ�գ����ؿ�
2 ���root�ڵ��������һ��������root
3 ������ǲ����ݹ���������������
4.1  �����������Ϊ�գ�������Ϊ�գ�������û���κ�һ���ڵ㣬����left�Ľ��
4.2  ���������Ϊ�գ���������Ϊ�գ�������û���κ�һ���ڵ㣬����right�Ľ��
4.2  �����������Ϊ�գ�������Ҳ��Ϊ�գ�˵���������ҵ�һ���ڵ㣬�������ҵ�һ���ڵ㣬������Ϊroot������root

˼·2  �ݹ飬���������DFS�ҵ�����·�����󹫹����㡣
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
        //�������
        if (root == a) return true;
        if(get_path(root->left,a,path))
            return true;
        if(get_path(root->right,a,path))
            return true;
        path.pop_back();
        return false;
    }
};