#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


/* 
合并多个有序链表
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *resHead = new ListNode(0);
        ListNode *pcur = resHead;
        int size = lists.size();
        if(size<1)
            return NULL;
        ListNode *p[size];
        for (int i = 0; i < size; i++)
        {
            p[i] = lists[i];
        }
        int min = INT_MAX;
        int min_index = 0;
        while (1)
        {
            min = INT_MAX;
            for (int i = 0; i < size; i++)
            {
                if(p[i]!=NULL)
                {
                    if(p[i]->val<min)
                    {
                        min = p[i]->val;
                        min_index = i;
                    }
                }
            }
            if(min==INT_MAX)
                break;
            pcur->next = p[min_index];
            pcur = p[min_index];
            p[min_index] = p[min_index]->next;
        }
        return resHead->next;
    }
};

int main()
{
    ListNode L11(1);
    ListNode L12(4);
    ListNode L13(5);
    ListNode L21(1);
    ListNode L22(3);
    ListNode L23(4);
    ListNode L31(2);
    ListNode L32(6);
    L11.next = &L12;
    L12.next = &L13;
    L21.next = &L22;
    L22.next = &L23;
    L31.next = &L32;
    vector<ListNode *> lists;
    lists.emplace_back(&L11);
    lists.emplace_back(&L21);
    lists.emplace_back(&L31);

    vector<ListNode *> lists1;
    lists1.emplace_back(&L31);
    Solution *p = new Solution();
    //ListNode * res = p->mergeKLists(lists);
    ListNode * res1 = p->mergeKLists(lists1);
    return 0;
}