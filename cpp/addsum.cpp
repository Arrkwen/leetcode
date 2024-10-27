/* 
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if(l1==nullptr)
            return l1;
        if(l2==nullptr)
            return l2;
        int carry = 0, remainder = 0, sum = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (p1 != nullptr || p2 != nullptr)
        {
            sum = 0;
            if(p1!=nullptr&&p2!=nullptr)
            {
                sum = p1->val + p2->val+ carry;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(p2!=nullptr)
            {
                sum = p2->val+carry;
                p2 = p2->next;
            }
            else
            {
                sum = p1->val+carry;
                p1 = p1->next;
            }
            if (sum >= 10)
            {
                remainder = sum - 10;
                carry = 1;
            }
            else
            {
                remainder = sum;
                carry = 0;
            }
            ListNode *res = new ListNode(remainder);
            tail->next = res;
            tail = res;
        }
        if(carry==1)
            tail->next = new ListNode(carry);
        return head->next;
    }
};