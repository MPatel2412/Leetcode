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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *curr = head->next;
        ListNode *prev = head;
        int index = 1;
        int firstIndex = 0;
        int minDistance = INT_MAX;
        int prevIndex = 0;
        while(curr->next != NULL)
        {
            if((curr->val > curr->next->val && curr->val > prev->val) ||
                curr->val < curr->next->val && curr->val < prev->val)
                {
                    if(prevIndex == 0)
                    {
                        firstIndex = index;
                        prevIndex = index;
                    }
                    else
                    {
                        minDistance = min(minDistance, index - prevIndex);
                        prevIndex = index;
                    }
                }
            index++;
            prev = curr;
            curr = curr->next;
        }
        vector<int> ans(2,-1);
        if(minDistance != INT_MAX)
        {
            ans[0] = minDistance;
            ans[1] = prevIndex - firstIndex;
        }
        return ans;
    }
};