
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


/* 
判断是否是一个二叉搜索树

中序遍历：如果当前元素比上一个元素小，则返回false
         如果遍历到最后一个元素，都是递增的，则返回ture
 */
//Definition for a binary tree node.
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
    bool isValidBST(TreeNode *root)
    {
        stack<pair<TreeNode *, bool>> s;
        s.push(make_pair(root, false));
        TreeNode *pcur = root;
        bool visited = false;
        long long preElement = LONG_LONG_MIN;
        while (!s.empty())
        {
            pcur = s.top().first;
            visited = s.top().second;
            s.pop();
            if (pcur == NULL)
                continue;
            if (visited)
            {
                if(pcur->val<=preElement)
                    return false;
                else
                    preElement = pcur->val;
            }
            else
            {
                s.push(make_pair(pcur->right, false));
                s.push(make_pair(pcur, true));
                s.push(make_pair(pcur->left, false));
            }
        }
        return true;
    }
};


int main()
{
    Solution p;
    TreeNode root(-2147483648);
    cout << p.isValidBST(&root)<<endl;
    return 0;
}