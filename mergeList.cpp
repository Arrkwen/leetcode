#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 

�ϲ�������������

 */

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* 

����������

����������
����һ��������

��������һ������
һ������  һ�������

���������һ��

 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *phead = new ListNode(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *ptail = phead;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val <= p2->val)
            {
                ptail->next = p1;
                ptail = p1;
                p1 = p1->next;
            }
            else
            {
                ptail->next = p2;
                ptail = p2;
                p2 = p2->next;
            }
        }
        while (p1 != NULL)
        {
            ptail->next = p1;
            ptail = p1;
            p1 = p1->next;
        }
        while (p2 != NULL)
        {
            ptail->next = p2;
            ptail = p2;
            p2 = p2->next;
        }
        return phead->next;
    }
};