class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;        // copy data
        ListNode* temp = node->next;        // store next node
        node->next = node->next->next;      // bypass next
        delete temp;                        // free memory
    }
};
