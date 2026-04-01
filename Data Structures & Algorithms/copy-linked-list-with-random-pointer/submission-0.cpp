class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. First Pass: Create all new nodes and map old pointers to new pointers.
        std::unordered_map<Node*, Node*> old_to_new;
        Node* curr = head;

        // Create the copy of every node and store the mapping
        while (curr != nullptr) {
            // Create a new node with the value of the original node
            Node* newNode = new Node(curr->val);
            old_to_new[curr] = newNode;
            curr = curr->next;
        }

        // 2. Second Pass: Set the 'next' and 'random' pointers in the new list.
        curr = head; // Start back at the original head
        Node* curr_copy = old_to_new[head]; // Start at the new head

        while (curr != nullptr) {
            // Set 'next' pointer
            // If original node has a next, look up its copy in the map.
            if (curr->next) {
                old_to_new[curr]->next = old_to_new[curr->next];
            }

            // Set 'random' pointer
            // If original node has a random, look up its copy in the map.
            if (curr->random) {
                old_to_new[curr]->random = old_to_new[curr->random];
            }
            
            curr = curr->next;
        }

        // Return the copy of the original head node
        return old_to_new[head];
    }
};