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
        vector<int> ans(2,-1);
        vector<int> arr;
        ListNode *temp = head;
        while(temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> index;
        for(int i=1; i<arr.size()-1;i++)
        {
            if(arr[i-1] > arr[i] && arr[i] < arr[i+1])
            {
                index.push_back(i);
            }
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
            {
                index.push_back(i);
            }
        }
        if(index.empty() || index.size() < 2)
            return ans;
        
        ans[1] = abs(index[index.size()-1] - index[0]);
        int mini = INT_MAX;
        for(int i=1;i<index.size();i++)
        {
            mini = min(mini,index[i]-index[i-1]);
        }
        ans[0]=mini;

        return ans;

    }
};