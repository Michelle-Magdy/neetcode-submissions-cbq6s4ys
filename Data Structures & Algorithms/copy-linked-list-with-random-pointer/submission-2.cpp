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
        unordered_map<Node*,Node*> mp;
        Node* curr = head;
        while(curr != nullptr){
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        Node* nCurr = mp[head];
        while(curr !=nullptr){
            if(curr->random)
                nCurr->random = mp[curr->random];
            nCurr->next = mp[curr->next];
            nCurr = nCurr->next;
            curr = curr->next;
        }
        return mp[head];
    }
};
