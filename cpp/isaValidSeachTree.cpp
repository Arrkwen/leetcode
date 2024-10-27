
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


/* 
�ж��Ƿ���һ������������

��������������ǰԪ�ر���һ��Ԫ��С���򷵻�false
         ������������һ��Ԫ�أ����ǵ����ģ��򷵻�ture
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