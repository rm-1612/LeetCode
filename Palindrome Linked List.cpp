/*

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* c=head;
    ListNode* next;
    ListNode* prev=NULL;
    while(c!=NULL)
    {
        next=c->next;
        c->next=prev;
        prev=c;
        c=next;
    }
    return prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* head1=head;
        ListNode* head2;
        if(head==NULL || head->next==NULL)
            return true;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)
        head2=slow->next;
        else head2=slow;
        head2=reverse(head2);
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val!=head2->val)
                return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};
