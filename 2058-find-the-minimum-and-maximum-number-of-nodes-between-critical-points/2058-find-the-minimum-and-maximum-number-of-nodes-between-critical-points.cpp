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
        // base cases



        vector<int> cp;
        int idx = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        while(next != NULL){
            if(curr->val > next->val && curr->val > prev->val) cp.push_back(idx);
            else if(curr->val < next->val && curr->val < prev->val) cp.push_back(idx);
            prev = curr;
            curr = next;
            next = next->next;
            idx++;
        }
        int n = cp.size();
        // base cases
        if(n == 0 || n == 1) return {-1, -1};
        
        int maxdist = cp[n-1]-cp[0];
        int mindist = INT_MAX;
        for(int i=1; i<n; i++) mindist = min(mindist, cp[i]-cp[i-1]);
        return {mindist, maxdist};
    }
};