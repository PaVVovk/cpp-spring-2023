Node* mergeTwoLists(Node* list1, Node* list2){
    if (list2 == nullptr){
        return list1;
    }
    if (list1 == nullptr){
        return list2;
    }
    Node* tmp1 = list1;
    Node* tmp2 = list2;
    if (tmp1->data > tmp2->data){
        tmp1 = list2;
        tmp2 = list1;
    }
    Node* new_head = tmp1;
    Node* tmp1_next = tmp1->next;
    while (tmp1_next != nullptr){
        while ((tmp2 != nullptr) and (tmp2->data < tmp1_next->data)){
            tmp1->next = tmp2;
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
        }
        tmp1->next = tmp1_next;
        tmp1 = tmp1_next;
        tmp1_next = tmp1->next;
    }
    if (tmp2 != nullptr){
        tmp1->next = tmp2;
    }
    return new_head;
}