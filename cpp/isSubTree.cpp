#include<iostream>

using namespace std;

/* 

判断一棵树t是否是另一棵树s的子树

先序遍历找到t的根节点在s中的位置，然后二者递归访问子树

 */
//Definition for a binary tree node.
struct TreeNode {    int val;
   TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//版本1  递归版
class Solution {
public:
    bool sameTree(TreeNode* s, TreeNode* t)
    {
        if(!s&&!t)
            return 1;
        if(!s||!t)
            return 0;
        if(s->val==t->val)
        {
            return sameTree(s->left, t->left) && sameTree(s->right, t->right);
        }
        else
            return 0;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s||!t)
            return 0;
        return sameTree(s, t)||isSubtree(s->left,t)||isSubtree(s->right,t);
    }
};

//思路2  非递归的到整棵树的字符串s，和 t，使用KMP判断s中是否包含t;

int main()
{
    TreeNode root(3);
    TreeNode l1(4);
    TreeNode r1(5);
    TreeNode ll1(1);
    TreeNode lr1(2);

    TreeNode root1(4);
    TreeNode sl1(1);
    TreeNode sr1(2);

    root.left = &l1;
    root.right = &r1;
    l1.left = &ll1;
    l1.right = &lr1;

    root1.left = &sl1;
    root1.right = &sr1;

    Solution p;
    bool res = p.isSubtree(&root, &root1);
    cout << res <<endl;
    return 0;
}