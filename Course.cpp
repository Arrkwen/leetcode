#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* 

��ȱ����ķ�ʽ

 */
class Solution
{
public:
    //�γ̵���Ϣ����ǰ�γ����ֺͶ�Ӧ���Ⱦ����Լ�λ��
    typedef struct node
    {
        int pre;
        int cur;
        node *next;
        node(int _a, int _cur) : pre(_a), cur(_cur), next(NULL) {}
    } ListNode;

    int dfs(map<int, ListNode *> &high, map<int, bool> &tempRes, ListNode* pHead, vector<int> &res, map<int, bool> &visited)
    {
        //ͨ���ṹ����Ϣ��õ�ǰ�γ�
        int curCourse = pHead->cur;
        //�ݹ���ʷ������е��Ⱦ��γ�
        while (pHead)
        {
            int preCourse = pHead->pre;
            //�жϵ�ǰ�Ⱦ����Ƿ���Ҫ�Ⱦ��Σ������Ҫ�ȷ����Ⱦ���
            if (high.count(preCourse))
            {
                //�жϵ�ǰ�Ⱦ����Ƿ�֮ǰ���ʹ������û�������
                if (!visited.count(preCourse))
                {
                    //���Ⱦ��ε�״̬��Ϊ1����ʾ���ʹ�
                    visited[preCourse] = 1;
                    //�õ��Ⱦ��εĵĽṹ����Ϣ
                    ListNode *pPre = high[preCourse];
                    if (!dfs(high, tempRes, pPre, res, visited))
                        return 0;
                }
                //�������ѭ����
                else
                {
                    if (!res.empty())
                        res.clear();
                    return 0;
                }
            }
            //���������һ���Ⱦ���
            pHead = pHead->next;
        }
        //����ѭ����˵���Ⱦ��γ��Ѿ������ˣ������γ̼�������
        if (!tempRes.count(curCourse))
        {
            tempRes[curCourse] = 1;
            res.emplace_back(curCourse);
            high.erase(curCourse);
        }
        return 1;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        //map<int>High �������Ⱦ��Σ�����ֵΪkey������γ���Ϣ�ṹ��Ϊֵ������ݹ�
        map<int, bool> tempRes; //��¼������Ƿ������ֵ
        map<int, ListNode *> high;
        int rowSize = prerequisites.size();
        //���Ⱦ���ά����ת��Ϊhash�洢
        for (int i = 0; i < rowSize; i++)
        {
            ListNode *temp = new ListNode(prerequisites[i][1],prerequisites[i][0]);
            if (high.count(prerequisites[i][0]))
            {
                ListNode *head = high[prerequisites[i][0]];
                while (head->next)
                {
                    head = head->next;
                }
                head->next = temp;
            }
            else
            {
                high[prerequisites[i][0]] = temp;
            }
        }
        //��û���Ⱦ��εĿγ̼�������
        int j = numCourses - 1;
        while (j >= 0)
        {
            if (!high.count(j))
            {
                res.emplace_back(j);
                tempRes[j] = 1;
            }
            j--;
        }
        //˳���������ÿһ�����Ⱦ��γ̵Ŀ�
        for (int i = 0; i < rowSize; i++)
        {
            map<int, bool> visited;
            if (high.count(prerequisites[i][0]))
            {
                if (!dfs(high, tempRes, high[prerequisites[i][0]], res, visited))//�����ѭ��
                    break;
            }
        }
        return res;
    }
};


/* 
��������
https://mp.weixin.qq.com/s?__biz=MzA3MjU5NjU2NA==&mid=2455502896&idx=1&sn=df6f2c86e0f1de823f79087ba9e8eb33&chksm=88b34d0bbfc4c41d863b4b6d78309e6ae01e766b1a7826b4c326246dd2489df9d684e8091ece&scene=21#wechat_redirect

 */
int main()
{
    //vector<vector<int>> nums{{1, 0},{2,0},{3,1},{3,2}};
    //vector<vector<int>> nums{{2,1},{1,0}};
    vector<vector<int>> nums{{1,0},{1,2},{0,1}};
    Solution p;
    vector<int> res = p.findOrder(3, nums);
    return 0;
}