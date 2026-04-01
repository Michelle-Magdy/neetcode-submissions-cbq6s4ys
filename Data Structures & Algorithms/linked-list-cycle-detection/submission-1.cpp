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
    bool hasCycle(ListNode* head) {
        set<ListNode*> s;
        ListNode* curr = head;
        while(curr != nullptr){{
            if(s.find(curr) != s.end()){
                return true;
            }
            s.insert(curr);
            curr = curr->next;
        }}
        return false;
    }
};
