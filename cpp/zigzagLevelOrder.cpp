#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/* 
����һ����������������ڵ�ֵ�ľ���β�α����������ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���

���磺
����������?[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
���ؾ���β�α������£�

[
  [3],
  [20,9],
  [15,7]
]

˼·:

��������ã���left��right
ż������ã���right��left

����ʱ����������


 */
 //Definition for a binary tree node.
 struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int> levelNode;
        if(root==NULL)
            return res;
        vector<TreeNode*> oddQue;
        vector<TreeNode*> evenQue;
        TreeNode *pCur = root;
        oddQue.emplace_back(root);
        while(!oddQue.empty()||!evenQue.empty())
        {
            if(!oddQue.empty())
            {
                int size = oddQue.size();
                for(int i = size-1;i>=0;i--)
                {
                    pCur = oddQue[i];
                    levelNode.emplace_back(pCur->val);
                    if(pCur->left)
                        evenQue.emplace_back(pCur->left);
                    if(pCur->right)
                        evenQue.emplace_back(pCur->right);
                }
                oddQue.clear();
            }
            res.emplace_back(levelNode);
            levelNode.clear();
            if(!evenQue.empty())
            {
                int size = evenQue.size();
                for(int i = size-1;i>=0;i--)
                {
                    pCur = evenQue[i];
                    levelNode.emplace_back(pCur->val);
                    if(pCur->right)
                        oddQue.emplace_back(pCur->right);
                    if(pCur->left)
                        oddQue.emplace_back(pCur->left);
                }
                evenQue.clear();
            }
            res.emplace_back(levelNode);
            levelNode.clear();
        }
        return res;
    }
};

int main()
{
    TreeNode root(3);
    TreeNode rl(9);
    TreeNode rr(20);
    TreeNode rrl(15);
    TreeNode rrr(7);
    root.left = &rl;
    root.right = &rr;
    rr.left = &rrl;
    rr.right = &rrr;
    Solution p;
    p.zigzagLevelOrder(&root);
    return 0;
}