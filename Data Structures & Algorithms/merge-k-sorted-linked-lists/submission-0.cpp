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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* start = new ListNode(0);
        ListNode* curr = start;

        while(true){
            int minVal = 1001;
            int minIndex = -1;
            for(int i =0;i<lists.size();i++){
                if(lists[i] != nullptr){
                    if(lists[i]->val < minVal){
                        minVal = lists[i]->val;
                        minIndex = i;
                    }
                }
            }
            if(minIndex == -1) break;
            lists[minIndex] = lists[minIndex]->next;
            curr->next = new ListNode(minVal);
            curr = curr->next;
           
        }
        ListNode* ret = start->next;
        delete start;
        return ret;
        
    }
};
