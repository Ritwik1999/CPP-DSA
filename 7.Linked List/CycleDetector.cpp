bool has_cycle(Node* head) {
    if (!head) {
        return false;
    }
    
    Node *slow = head, *fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;            
        }
    }
    
    return false;    
}