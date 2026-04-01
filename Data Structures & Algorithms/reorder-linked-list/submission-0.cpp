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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(second != nullptr){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

       ListNode* f = head;
       ListNode* s = prev;

        while(s!= nullptr){
            ListNode* t1 = f->next;
            ListNode* t2 = s->next;
            f->next = s ;
            s->next = t1;
            f= t1;
            s = t2;
        }
    }
};
