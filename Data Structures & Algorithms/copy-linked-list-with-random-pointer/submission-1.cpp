/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        if(!head->next) return new Node(head->val);
        unordered_map<Node*,Node*> mp;
        Node* curr = head->next;
        Node* head2 = new Node(head->val);
        head2->random = head->random;
        mp[head] = head2;
        Node* prev = head2;
        
        while(curr != nullptr){
            Node* newNode = new Node(curr->val);
            newNode->random = curr->random;
            prev->next = newNode;
            prev = prev->next;
            mp[curr] = prev;
            curr = curr->next;
        }

        curr = head2;
        while(curr !=nullptr){
            if(curr->random)
                curr->random = mp[curr->random];
            curr = curr->next;
        }
        return head2;
    }
};
