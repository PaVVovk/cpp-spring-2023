void push_back(Node* &head, int new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        return;
    }
    Node* current = head;
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = new Node;
    current->next->key = new_key;
}

Node* read_list(Node* head){
    int tmp;
    cin >> tmp;
    while (tmp != 0){
        push_back(head, tmp);
        cin >> tmp;
    }
    return head;
}

Node* reverse(Node* head){
	if (head == nullptr){
        return head;
    }
    Node* tmp = head;
    Node* tmp_prev = nullptr;
    Node* tmp_next = tmp->next;
    while (tmp != nullptr){
        tmp->next = tmp_prev;
        if (tmp_next != nullptr){
            tmp_prev = tmp;
            tmp = tmp_next;
            tmp_next = tmp->next;
        } else {
            head = tmp;
            tmp = tmp_next;
        }
    }
    return head;
}