/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp = head;
        ListNode *curr;
        while(temp != NULL)
        {
            if(temp->val == 0)
            {
                int sum = 0;
                curr = temp->next;
                while(curr != NULL && curr->val  != 0)
                {
                    sum += curr->val;
                    curr = curr ->next; 
                }
                temp ->val = sum;
                if(curr->next != NULL)
                    temp->next = curr;
                else
                    temp->next = NULL;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;




        return head;
    }
};