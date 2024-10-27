
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* 
Ѱ�Ҷ����������е�������
  1 �������������������ֵС�ڵ��ڵ�ǰ����ֵ
  2 �������������������ֵ���ڵ��ڵ�ǰ����ֵ
  3 �����������������Ƕ���������

�������ÿһ���ڵ㣬��¼�ڵ���ͬ�ĸ�����

preElement��¼ǰһ����
vector<int>mode:��¼����
maxNum:��¼�����ĸ���

�����ж�����������������������һ���ǵݼ������У����Խ������������ͨ���Ƚ�ǰһ��Ԫ��pre�͵�ǰԪ��cur��ֵȷ���Ƿ�ִ�в�������������

���pre�����ڣ�˵��Ŀǰ���ڵ�һ��Ԫ�ص�λ�ã����Խ�������Ϊ1������ӵ�ǰԪ�ؽ���������
���pre���ڣ��ȷ������������
���pre->val == cur->val��˵����ǰֵ��ǰһ����ͬ��������1,count++
���pre->val ��= cur->val��˵����ǰֵ��ǰһ����ͬ��������Ϊ1,count = 1
�ڵõ�����count���뵱ǰ������maxnum�Ƚϣ�

���count > maxnum : ����maxnum����ս������res�����cur->val
���count == maxnum ��ֻ�����cur->val

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
        int maxNum = 1;//��ʾһ����Ч��preElement.
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
        //�������һ���ڵ�
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