#include <iostream>

using std::endl;
using std::cout;
using std::cin;

struct Node{
    int key = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct List{
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};

List* create_empty_list(){
    List* list = new List;
    list->NIL = new Node;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}

List* push_front(List* list_ptr, int new_key){
    if (list_ptr == nullptr){
        return list_ptr;
    }
    Node* new_head = new Node;
    new_head->prev = list_ptr->NIL;
    list_ptr->NIL->next = new_head;
    if ((list_ptr->HEAD == list_ptr->NIL) and (list_ptr->TAIL == list_ptr->NIL)){
        new_head->next = list_ptr->NIL;
        list_ptr->NIL->prev = new_head;
        list_ptr->TAIL = new_head;
        list_ptr->TAIL->key = new_key;
    } else {
        new_head->next = list_ptr->HEAD;
        list_ptr->HEAD->prev = new_head;
    }
    list_ptr->HEAD = new_head;
    list_ptr->HEAD->key = new_key;
    list_ptr->size++;
    return list_ptr;
}

List* push_back(List* list_ptr, int new_key){
    if (list_ptr == nullptr){
        return list_ptr;
    }
    Node* new_tail = new Node;
    new_tail->next = list_ptr->NIL;
    list_ptr->NIL->prev = new_tail;
    if ((list_ptr->HEAD == list_ptr->NIL) and (list_ptr->TAIL == list_ptr->NIL)){
        new_tail->prev = list_ptr->NIL;
        list_ptr->NIL->next = new_tail;
        list_ptr->HEAD = new_tail;
        list_ptr->HEAD->key = new_key;
    } else {
        new_tail->prev = list_ptr->TAIL;
        list_ptr->TAIL->next = new_tail;
    }
    list_ptr->TAIL = new_tail;
    list_ptr->TAIL->key = new_key;
    list_ptr->size++;
    return list_ptr;
}

List* insert_after(List* list_ptr, Node* prev_ptr, int new_key){
    if ((list_ptr == nullptr) or (prev_ptr == nullptr)){
        return list_ptr;
    }
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->prev = prev_ptr;
    
    if ((list_ptr->HEAD == list_ptr->NIL) and (list_ptr->TAIL == list_ptr->NIL)){
        prev_ptr->next = new_node;
        prev_ptr->prev = new_node;
        new_node->next = prev_ptr;
        
        list_ptr->HEAD = new_node;
        list_ptr->TAIL = list_ptr->HEAD;
    } else {
        new_node->next = prev_ptr->next;
        prev_ptr->next->prev = new_node;
        prev_ptr->next = new_node;
        
        if (prev_ptr == list_ptr->NIL){
            list_ptr->HEAD = new_node;
        } else if (prev_ptr == list_ptr->TAIL){
            list_ptr->TAIL = new_node;
        }
    }
    list_ptr->size++;
    return list_ptr;
}

void print_list(const List* list_ptr){
    if (list_ptr == nullptr){
        cout << endl;
        return;
    }
    Node* tmp = list_ptr->HEAD;
    while (tmp != list_ptr->NIL){
        cout << tmp->key;
        tmp = tmp->next;
        if (tmp != list_ptr->NIL){
            cout << ' ';
        }
    }
    cout << endl;
}

void clear_list(List* list_ptr){
    if ((list_ptr == nullptr) or (list_ptr->NIL == list_ptr->HEAD)){
        return;
    }
    Node* tmp = list_ptr->HEAD;
    while (tmp->next != list_ptr->NIL){
        tmp = tmp->next;
        delete tmp->prev;
    }
    delete tmp;
    list_ptr->size = 0;
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
}

void destroy_list(List* list_ptr){
    if (list_ptr == nullptr){
        return;
    }
    if (list_ptr->HEAD == list_ptr->NIL) {
        delete list_ptr->NIL;
        delete list_ptr;
        return;
    }
    Node* tmp = list_ptr->HEAD;
    while (tmp->next != list_ptr->NIL){
        tmp = tmp->next;
        delete tmp->prev;
    }
    delete tmp;
    delete list_ptr->NIL;
    delete list_ptr;
}

Node* find_key(List* list_ptr, int key){
    if (list_ptr == nullptr){
        return nullptr;
    }
    if (list_ptr->HEAD == list_ptr->NIL) {
        return list_ptr->NIL;
    }
    Node* tmp = list_ptr->HEAD;
    while ((tmp->key != key) and (tmp->next != list_ptr->NIL)){
        tmp = tmp->next;
    }
    if ((tmp->next != list_ptr->NIL) or (tmp->key == key)){
        return tmp;
    }
    return list_ptr->NIL;
}

void remove_key(List* list_ptr, int key){
    if ((list_ptr == nullptr) or (list_ptr->HEAD == list_ptr->NIL)){
        return;
    }
    Node* tmp = list_ptr->HEAD;
    while ((tmp->key != key) and (tmp->next != list_ptr->NIL)){
        tmp = tmp->next;
    }
    if (tmp->key == key){
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        if (tmp->prev == list_ptr->NIL){
            list_ptr->HEAD = tmp->next;
        }
        if (tmp->next == list_ptr->NIL){
            list_ptr->TAIL = tmp->prev;
        }
        list_ptr->size--;
        delete tmp;
    }
}

int main(){
    List* list = create_empty_list();
    for (int i = 0; i < 10; i++){
        list = push_back(list, i);
    }
    print_list(list);
    return 0;
}