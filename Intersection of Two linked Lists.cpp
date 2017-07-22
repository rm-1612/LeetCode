/*

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int count(ListNode* head)
{
    int ctr=0;
    while(head!=NULL)
    {
        ++ctr;
        head=head->next;
    }
    return ctr;
}
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL)
            return NULL;
        if(headB==NULL)
            return NULL;
        int c1=count(headA);
        int c2=count(headB);
        int ctr=0;
        if(c2>c1)
        {
            ListNode* t=headA;
            headA=headB;
            headB=t;
            int temp=c2;
            c2=c1;
            c1=temp;
        }
        while(ctr<c1-c2)
        {
            headA=headA->next;
            ++ctr;
        }
        while(headA!=NULL && headB!=NULL)
        {
            if(headA->val==headB->val)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};
