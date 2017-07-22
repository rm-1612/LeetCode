/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool compare(ListNode* a,ListNode* b)
    {
        return a->val>b->val;
    }


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, std::function<bool(ListNode*, ListNode*)> > pq(compare);
        ListNode* result=NULL;
        ListNode* tail=NULL;
        if (lists.size()==0)
            return result;
        for(int i=0;i<lists.size();++i)
        {
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        while(!pq.empty())
        {
            ListNode* front=pq.top();
            pq.pop();
            if(result==NULL)
            {
                result=front;
                tail=front;
            }
            else 
            {
                tail->next=front;
                tail=front;
            }
            if(front->next!=NULL)
            pq.push(front->next);
        }
        return result;
    }
};
