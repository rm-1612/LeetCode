/*

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
        
    }
};
