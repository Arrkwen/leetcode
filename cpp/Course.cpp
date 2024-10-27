#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* 

深度遍历的方式

 */
class Solution
{
public:
    //课程的信息：当前课程名字和对应的先决课以及位置
    typedef struct node
    {
        int pre;
        int cur;
        node *next;
        node(int _a, int _cur) : pre(_a), cur(_cur), next(NULL) {}
    } ListNode;

    int dfs(map<int, ListNode *> &high, map<int, bool> &tempRes, ListNode* pHead, vector<int> &res, map<int, bool> &visited)
    {
        //通过结构体信息获得当前课程
        int curCourse = pHead->cur;
        //递归访问访问所有的先决课程
        while (pHead)
        {
            int preCourse = pHead->pre;
            //判断当前先决课是否还需要先决课，如果需要先访问先决课
            if (high.count(preCourse))
            {
                //判断当前先决课是否之前访问过，如果没有则访问
                if (!visited.count(preCourse))
                {
                    //将先决课的状态置为1，表示访问过
                    visited[preCourse] = 1;
                    //拿到先决课的的结构体信息
                    ListNode *pPre = high[preCourse];
                    if (!dfs(high, tempRes, pPre, res, visited))
                        return 0;
                }
                //否则出现循环。
                else
                {
                    if (!res.empty())
                        res.clear();
                    return 0;
                }
            }
            //否则访问下一个先决课
            pHead = pHead->next;
        }
        //出了循环，说明先决课程已经结束了，将本课程加入结果中
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
        //map<int>High 表明有先决课，以其值为key，以其课程信息结构体为值，方便递归
        map<int, bool> tempRes; //记录结果中是否有这个值
        map<int, ListNode *> high;
        int rowSize = prerequisites.size();
        //将先决二维数组转化为hash存储
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
        //将没有先决课的课程加入结果中
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
        //顺序遍历遍历每一个有先决课程的课
        for (int i = 0; i < rowSize; i++)
        {
            map<int, bool> visited;
            if (high.count(prerequisites[i][0]))
            {
                if (!dfs(high, tempRes, high[prerequisites[i][0]], res, visited))//如果有循环
                    break;
            }
        }
        return res;
    }
};


/* 
拓扑排序
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