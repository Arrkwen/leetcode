
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* 
寻找二叉搜索树中的众数：
  1 结点左子树中所含结点的值小于等于当前结点的值
  2 结点右子树中所含结点的值大于等于当前结点的值
  3 左子树和右子树都是二叉搜索树

中序遍历每一个节点，记录节点相同的个数。

preElement记录前一个数
vector<int>mode:记录众数
maxNum:记录众数的个数

本题中二叉搜索树的中序遍历结果是一个非递减的序列，所以进行中序遍历，通过比较前一个元素pre和当前元素cur的值确定是否执行操作，具体如下

如果pre不存在，说明目前是在第一个元素的位置，所以将计数置为1，并添加当前元素进入结果数组
如果pre存在，先分两种情况计数
如果pre->val == cur->val：说明当前值和前一个相同，计数加1,count++
如果pre->val ！= cur->val：说明当前值和前一个不同，计数置为1,count = 1
在得到计数count后，与当前最大计数maxnum比较：

如果count > maxnum : 更新maxnum，清空结果数组res，添加cur->val
如果count == maxnum ：只需添加cur->val

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
    vector<int> findMode(TreeNode *root)
    {
        stack<pair<TreeNode *, bool>> s;
        s.push(make_pair(root, false));
        TreeNode *pcur = root;
        bool visited = false;
        int preElement = INT_MIN;
        int curNum = 0;
        int maxNum = 1;//表示一个无效点preElement.
        vector<int> mode;
        while (!s.empty())
        {
            pcur = s.top().first;
            visited = s.top().second;
            s.pop();
            if (pcur == NULL)
                continue;
            if (visited)
            {
                if (preElement == pcur->val)
                    curNum++;
                else
                {
                    if (curNum > maxNum)
                    {
                        mode.clear();
                        mode.emplace_back(preElement);
                        maxNum = curNum;
                    }
                    else if (curNum == maxNum)
                    {
                        mode.emplace_back(preElement);
                    }
                    curNum = 1;
                    preElement = pcur->val;
                }
            }
            else
            {
                s.push(make_pair(pcur->right, false));
                s.push(make_pair(pcur, true));
                s.push(make_pair(pcur->left, false));
            }
        }
        //处理最后一个节点
        if (curNum > maxNum)
        {
            mode.clear();
            mode.emplace_back(preElement);
            maxNum = curNum;
        }
        else if (curNum == maxNum)
        {
            mode.emplace_back(preElement);
        }
        return mode;
    }
};

int main()
{
    Solution p;
    TreeNode root(1);
    TreeNode l(1);
    TreeNode r(2);
    root.left = &l;
    root.right = &r;
    vector<int> res = p.findMode(&root);
    return 0;
}