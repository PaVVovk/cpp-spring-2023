int find_middle(const Node* head){
    Node* slow = head->next;
    if (slow == nullptr){
        return head->value;
    }
    Node* fast = slow->next;
    while ((fast != nullptr) && (fast->next != nullptr)){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}