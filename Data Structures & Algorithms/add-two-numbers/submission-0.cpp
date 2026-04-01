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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        ListNode* newList = new ListNode(sum %10);
        sum /= 10;
        int carry = sum % 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* prev = newList;
        while(l1 != nullptr && l2 != nullptr){
            sum = l1->val + l2->val + carry;
            prev->next = new ListNode((sum) % 10); 
            sum /= 10;
            carry = sum % 10;
            prev = prev->next; 
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!= nullptr){
            sum = l1->val + carry;
            prev->next = new ListNode((sum) % 10); 
            sum /= 10;
            carry = sum % 10;
            prev = prev->next; 
            l1 = l1->next;
        }
        while(l2!= nullptr){
            sum = l2->val + carry;
            prev->next = new ListNode((sum) % 10); 
            sum /= 10;
            carry = sum % 10;
            prev = prev->next; 
            l2 = l2->next;
        }
        if(carry){
            prev->next = new ListNode(carry % 10); 
        }
        return newList;
    }
};
